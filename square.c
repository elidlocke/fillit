/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:36:41 by enennige          #+#    #+#             */
/*   Updated: 2018/03/05 17:37:35 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "square.h"

/*
** The function make_square_str() makes a square array of strings, with a
** width and height equal to size. Each character in the array of strings is
** then initialized to '.'
*/

char	**make_square_str(size_t size)
{
	char	**square;
	size_t	i;

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

/*
** The function make_square_struct() makes a structure for a square to be filled,
** which contains the size of the square and a string array filled with '.'
*/
t_square	*make_square_struct(size_t size)
{
	t_square *square;
	
	square = (t_square *)ft_memalloc(sizeof(*square));
	square->str_array = make_square_str(size);
	square->size = size;
	
	return (square);
}

/*
** The function print_str_square() takes a character array
** and prints it out, with a newline after each line.
*/

void	print_str_square(char **square)
{
	int i;

	if (square)
	{
		i = 0;
		while (square[i] != NULL)
		{
			ft_putstr(square[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
	{
		ft_putstr("square is null\n");
	}
}
