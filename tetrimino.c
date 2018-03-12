/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:55:20 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/11 17:24:40 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "tetrimino.h"

static int	validate_block(const char *shape, int len, int *sides)
{
	int x;
	int y;
	int curr_sides;

	x = len % 5;
	y = ((len + 5) / 5);
	curr_sides = 0;
	if (y > 0)
		y -= 1;
	if ((y - 1) >= 0 && shape[x + (y - 1) * 5] == BLOCK)
		curr_sides++;
	if ((y + 1) < 4 && shape[x + (y + 1) * 5] == BLOCK)
		curr_sides++;
	if ((x - 1) >= 0 && shape[x - 1 + y * 5] == BLOCK)
		curr_sides++;
	if ((x + 1) < 4 && shape[x + 1 + y * 5] == BLOCK)
		curr_sides++;
	if (curr_sides)
		*sides += curr_sides;
	return (curr_sides ? 1 : 0);
}

static void	set_minmax_points(t_point ***points, int *max_x,
								int blocks, int len)
{
	(*max_x) = (int)(len % 5) > *max_x ? (int)(len % 5) : *max_x;
	if (blocks == 0 || blocks == 3)
		(*points)[blocks == 0 ? 0 : 1] = create_point(len);
	else if ((int)(len % 5) < (*points)[0]->x)
		(*points)[0]->x = len % 5;
}

static int	invalid_block(t_point ***points)
{
	free_minmax_points(points);
	return (0);
}

int			validate_tetrimino(const char *shape, t_point ***points)
{
	size_t	len;
	int		blocks;
	int		max_x;
	int		sides;

	len = -1;
	blocks = 0;
	max_x = 0;
	sides = 0;
	while (shape[++len])
	{
		if (((len + 1) % 5 == 0 && shape[len] != NEWLINE) ||
		(shape[len] != NEWLINE && shape[len] != EMPTY && shape[len] != BLOCK))
			return (invalid_block(points));
		else if (shape[len] == BLOCK)
		{
			if (blocks > 4 || !validate_block(shape, len, &sides))
				return (invalid_block(points));
			set_minmax_points(points, &max_x, blocks++, len);
		}
	}
	if (!blocks || blocks != 4 || sides < 6)
		return (invalid_block(points));
	(*points)[1]->x = max_x > (*points)[1]->x ? max_x : (*points)[1]->x;
	return (1);
}
