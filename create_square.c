/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:21 by enennige          #+#    #+#             */
/*   Updated: 2018/03/05 12:30:31 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// struct start - remove this and put in header file
typedef struct	s_tetri
{
	char		**shape;
	int			width;
	int			height;
}				t_tetri;
typedef struct	s_point
{
	int 		x;
	int			y;
}				t_point;
// struct end

/*
** Checks if a tetrimino will fit in a grid
*/
int		check_tetrimino_fits(t_tetri *tetrimino, char **square, t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;

	x = 0;
	y = 0;
	tetri_shape = tetrimino->shape;
	while (tetri_shape[y] != NULL)
	{
		while (tetri_shape[y][x] != '\0')
		{
			if (!(square[y + point->y][x + point->x] == '.' ||
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

char	**place_a_tetrimino(t_tetri *tetrimino, char **square,
							t_point *point, char order)
{
	int		x;
	int		y;
	char	**tetri_shape;

	x = 0;
	y = 0;
	if (check_tetrimino_fits(tetrimino, square, point) == 1)
	{	
		tetri_shape = tetrimino->shape;
		while (tetri_shape[y] != NULL)
		{
			while (tetri_shape[y][x] != '\0')
			{
				ft_putstr("LOOP ");
				if (tetri_shape[y][x] != '.')
				{
					square[y + point->y][x + point->x] = order;
				}
				x++;
			}
			y++;
		}
		return (square);
	}
	return (NULL);
}

char	**make_str_square(size_t size)
{
	char **square;
	size_t i;

	square = (char **)ft_memalloc((sizeof(*square) * (size + 1)));
	if (!square)
		return (NULL);
	i = 0;
	while (i < size)
	{
		square[i] = ft_strnew(size);
		if (!(square[i]))
			return (NULL);
		ft_memset(square[i], '.', size);
		i++;
	}
	return (square);
}

void	print_str_square(char **square)
{
	int i;
	i = 0;
	while (square[i] != NULL)
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}

int main(void)
{
	char **square;
	square = make_str_square(3);

	// initialize a dummy tetrimino
	char shape_l1[] = "##.";
	char shape_l2[] = ".##";
	char *shapes[3] = {shape_l1, shape_l2, NULL};	
	t_tetri *tetri = (t_tetri *)ft_memalloc(sizeof(*tetri));
	tetri->shape = shapes;
	tetri->width = 4;
	tetri->height = 1;
	// end dummy tetrimino
	// dummy point
	t_point *point = (t_point *)ft_memalloc(sizeof(*point));
	point->x = 0;
	point->y = 0;	
	// end dummy point

	print_str_square(square);
	
	if (check_tetrimino_fits(tetri,square,point) == 1)
		ft_putstr("SUCCESS\n");
	else
		ft_putstr("NOPE\n");
	square = place_a_tetrimino(tetri, square, point, 'A');
	print_str_square(square);
}
