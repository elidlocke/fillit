/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:55:20 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/06 15:45:12 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "tetrimino.h"

int		xy_to_len(int x, int y)
{
	return (x + y * 5);
}

int		validate_block(const char *shape, int len)
{
	int x;
	int y;

	x = len % 5;
	y = ((len + 5) / 5);
	if (y > 0)
		y -= 1;
	if ((y - 1) >= 0 && shape[xy_to_len(x, y - 1)] == BLOCK)
		return (1);
	if ((y + 1) < 4 && shape[xy_to_len(x, y + 1)] == BLOCK)
		return (1);
	if ((x - 1) >= 0 && shape[xy_to_len(x - 1, y)] == BLOCK)
		return (1);
	if ((x + 1) < 4 && shape[xy_to_len(x + 1, y)] == BLOCK)
		return (1);
	return (0);
}

int		validate_tetrimino(const char *shape, t_point ***points)
{
	size_t	len;
	int		blocks;

	len = 0;
	blocks = 0;
	while (shape[len])
	{
		if ((len + 1) % 5 == 0 && shape[len] != NEWLINE)
			return (0);
		else if (shape[len] == BLOCK)
		{
			if (blocks > 4 || !validate_block(shape, len))
			{
				free_minmax_points(points);
				return (-1);
			}
			if (blocks == 0 || blocks == 3)
				(*points)[blocks == 0 ? 0 : 1] = create_point(len);
			blocks++;
		}
		len++;
	}
	return (1);
}

char	**create_tetrimno_shape(int height, int width)
{
	char	**shape;
	int		row;

	if ((shape = (char **)ft_memalloc(sizeof(*shape) * height + 1)))
	{
		row = 0;
		while (row < height)
		{
			if (!(shape[row] = ft_strnew(width)))
			{
				while (--row)
					ft_strdel(&shape[row]);
				return (NULL);
			}
			ft_memset(shape[row++], EMPTY, width);
		}
		shape[row] = NULL;
	}
	return (shape);
}

void	fill_tetrimino(const char *raw_shape, const char fill, t_tetri *new)
{
	int	curr_y;
	int curr_x;

	curr_y = 0;
	curr_x = xy_to_len(new->start->x, new->start->y);
	while (curr_y < new->height)
	{
		ft_memcpy(new->shape[curr_y], &raw_shape[curr_x], new->width);
		ft_strcre(new->shape[curr_y], BLOCK, fill);
		curr_y++;
		curr_x += 5;
	}
}

void	free_tetrimino(t_tetri **tetri)
{
	int height;

	if (!tetri)
		return ;
	free_point(&((*tetri)->start));
	if ((*tetri)->shape)
	{
		height = 0;
		while (height < (*tetri)->height)
			ft_strdel(&((*tetri)->shape[height++]));
		free((*tetri)->shape);
	}
	free(*tetri);
	*tetri = NULL;
}

t_tetri	*create_tetrimino(const char *raw_shape, const char fill)
{
	t_tetri *tetri;
	t_point **points;

	if (!raw_shape || !(points = (t_point **)ft_memalloc(sizeof(*points) * 2)))
		return (NULL);
	if (!validate_tetrimino(raw_shape, &points))
		return (NULL);
	if ((tetri = (t_tetri *)ft_memalloc(sizeof(*tetri))))
	{
		tetri->height = ((points[1])->y - (points[0])->y) + 1;
		tetri->width = ((points[1])->x - (points[0])->x) + 1;
		tetri->start = points[0];
		if (!(tetri->shape = create_tetrimno_shape(tetri->height, tetri->width)))
			return (NULL);
		fill_tetrimino(raw_shape, fill, tetri);
	}
	return (tetri);
}
