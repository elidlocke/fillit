/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:21 by enennige          #+#    #+#             */
/*   Updated: 2018/03/04 18:16:53 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**make_str_square(size_t size)
{
	char **square;
	size_t i;
	size_t j;

	square = (char **)ft_memalloc((sizeof(*square) * (size + 1)));
	if (!square)
		return (NULL);
	i = 0;
	while (i < size)
	{
		square[i] = ft_strnew(size);
		if (!(square[i]))
			return (NULL);
		j = 0;
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
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

/*
int main(void)
{
	char **square;

	square = make_str_square(3);
	print_str_square(square);
}
*/
