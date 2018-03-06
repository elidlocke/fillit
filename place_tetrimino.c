/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:21:09 by enennige          #+#    #+#             */
/*   Updated: 2018/03/05 16:02:29 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "tetrimino.h"
#include "square.h"

/*
** The function check_tetrimino_max() checks if a tetrimino's size will
** overflow a board. Returns 1 if all is good, or 0 if the tetrimino's
** attempted coordinates are outside the board.
*/

int		check_tetrimino_max(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	if ((point->y + tetrimino->height < square->size) &&
		(point->x + tetrimino->width < square->size))
		return (1);
	return (0);
}

/*
** The function check_tetrimino_fits() checks if a tetrimino will fit in a
** grid at a given point. If the tetrimino does not fit, the function
** returns NULL.
*/

int		check_tetrimino_fits(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->str_array;
	if (check_tetrimino_max(tetrimino, square, point) != 1)
		return (0);
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (!(str_square[y + point->y][x + point->x] == '.' ||
				tetri_shape[y][x] == '.'))
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/*
** The function place_a_tetrimino() draws a tetrimino on a square board,
** aligning the top left corner of the tetrimino with the point specified.
** The tetrimino is drawn in the character specified (eg. AAAA).
*/

char	**place_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point, char order)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	if (check_tetrimino_fits(tetrimino, square, point) == 1)
	{
		tetri_shape = tetrimino->shape;
		str_square = square->str_array;
		while (tetri_shape[y] != NULL)
		{
			x = 0;
			while (tetri_shape[y][x] != '\0')
			{
				if (tetri_shape[y][x] != '.')
					str_square[y + point->y][x + point->x] = order;
				x++;
			}
			y++;
		}
		return (str_square);
	}
	return (NULL);
}

/*
** The function remove_a_tetrimino() removes a tetrimino from the board
*/

char	**remove_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->str_array;
	while ((tetrimino->shape)[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_square[y + point->y][x + point->x] = '.';
			}
			x++;
		}
		y++;
	}
	return (str_square);
}
