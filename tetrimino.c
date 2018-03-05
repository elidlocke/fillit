/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:55:20 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/04 18:09:08 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetrimino.h"

t_point		*create_point(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = (len + 5 - 1) /	5;
	}
	return (point);
}

void		free_points(t_point **points, int blocks)
{
	int count;

	if (!points || !blocks)
		return ;
	count = (blocks >= 1 && blocks <= 2) ? 1 : 2;
	while (count--)
		free(*points++);
	*points = NULL;
}

static int	xy_to_len(int x, int y)
{
	return (x + (y - 1) * 5);
}

static int	validate_block(const char *shape, int len)
{
	int x;
	int y;

	x = len % 5;
	y = (len + 5 - 1) / 5;
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

static int	validate_tetrimino(const char *shape, t_points **points)
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
				free_points(points, blocks);
				return (-1);
			}
			if (blocks == 0 || blocks == 2)
				points[blocks == 0 ? 0 : 1] = create_point(len);
			blocks++;
		}
		len++;
	}
	return (1);
}

static char	**create_tetrimno_shape(int height, int width)
{
	char	**shape;
	int		row;

	if ((shape = (char **)ft_memalloc(sizeof(*shape) * height + 1)))
	{
		row = 0;
		while (row < height)
		{
			shape[row] = ft_strnew(width);
			ft_memset(shape[row++], EMPTY, width - 1);
		}
	}
	shape[row] = 0;
	return (shape);
}

static void	fill_tetrimino(const char *raw_shape, const char fill, int width, int height, char **shape)
{
	t_point *start;
	int	curr_y;
	int len;

	len = 0;
	start = NULL;
	curr_y = 0;
	while (raw_shape[len])
	{
		if (raw_shape[len] == BLOCK && !start)
			start = create_point(len);
		if (raw_shape[len] == BLOCK)
			/* TODO: COPY USING POSITIONS AWARE */
			ft_memcpy(shape[curr_y++], raw_shape[len], width);
		else if (raw_shape[len] == NEWLINE)
		{
			curr->x = 0;
			curr->y++;
		}
		curr->x++;
		len++;
	}
}

t_tetri		*create_tetrimno(const char *raw_shape, const char fill)
{
	t_tetri *new;
	t_point **points;

	if (!raw_shape || !validate_tetrimino(raw_shape, points))
		return (NULL);
	if ((new = (t_tetri *)ft_memalloc(sizeof(*new))))
	{
		new->width = (points[1])->y - (points[0])->y;
		new->height = (points[1])->x - (points[0])->x;
		new->shape = create_tetrimno_shape(new->height, new->width);
		fill_tetrimino(raw_shape, fill, new->shape);
	}
	return (new);
}
