/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:40:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/07 12:25:56 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "read.h"
#include "square.h"
#include "tetrimino.h"

int	get_next_point(t_point **point, char **square)
{
	t_point *new;

	if (!square)
		return (0);
	if (!point && (new = create_point(0)))
	{
		point = &new;
		return (1);
	}
	(*point)->x = (*point)->x + 1;
	while (square[(*point)->y] != NULL)
	{
		while (square[(*point)->y][(*point)->x] != '\0')
		{
			if (square[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}

int solve_a_square(t_square *square, t_list **block)
{
	char	**rows;
	t_point	*p_start;

	if (!block || !*block)
	{
		print_str_square(square->rows);
		return (1);
	}
	while (block)
	{
		// FIND XY
		while (get_next_point(&p_start, square->rows))
		{
			// VALIDATE A BLOCK
			// IF IT FITS, BREAK
			if ((rows = place_a_tetrimino((t_tetri *)(*block)->content, square, p_start)))
				break ;
		}
		// CANT PLACE A BLOCK
		if (!rows)
			return (0);
		// PLACE A BLOCK
		update_square(&square, rows);
		(*block) = (*block)->next;
		// RECURSE
		return (solve_a_square(square, block));
	}
	return (0);
}

int	solve_squares(t_list **tetri_lst)
{
	t_square	*square;
	size_t		square_size;

	square_size = 2;
	if (!(square = create_square(square_size)))
		return (0);
	while (!solve_a_square(square, tetri_lst))
	{
		free_square(&square);
		if (!(square = create_square(++square_size)))
			return (0);
	}
	return (1);
}

int solve(const char *filename)
{
	t_list		*tetri_lst;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
	if (!solve_squares(&tetri_lst))
		return (0);
	return (1);
}
