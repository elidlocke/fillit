/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:40:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/07 10:08:11 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "read.h"
#include "square.h"
#include "tetrimino.h"

int	get_next_point(t_point point, char **square)
{
}

int solve(const char *filename)
{
	t_list		*tetri_lst;
	t_list		*block;
	t_point		*p_start;
	t_square	*square;
	size_t		square_size;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
	square_size = 2;
	if (!(square = create_square(square_size)))
		return (0);
	block = tetri_lst;
	while (block)
	{
		// FIND XY
		p_start = get_start_point(square->rows);
		// PLACE A BLOCK
		if (!(square->rows = place_a_tetrimino((t_tetri *)block->content, square, p_start)))
			return (0); // DO SOMETHING HERE, I FORGOT
		free_point(&p_start);
		block = block->next;
	}
	if (!block)
	{
		print_str_square(square->rows);
		return (1);
	}
	return (0);
}
