/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:55:20 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/04 11:48:44 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetrimino.h"

static int	validate_tetrimino(const char *shape, int *max_wh)
{
	max_wh[0] = 0;
	max_wh[1] = 0;
	return (0);
}

t_tetri *create_tetrimno(const char *raw_shape, const char fill)
{
	t_tetri *new;
	char	*row[4];
	size_t	tetri_width;
	size_t	tetri_height;
	int		*max_wh;

	if (!validate_tetrimino(raw_shape, max_wh))
		return (NULL);
	if ((new = (t_tetri *)ft_memalloc(sizeof(*new))))
	{
		tetri_width = 0;
		tetri_height = 0;
		while (*raw_shape)
		{
			if (*raw_shape != NEWLINE && *raw_shape == BLOCK)
				tetri_width++;
			else if (*raw_shape == NEWLINE)
			{
				row[tetri_height] = ft_strnew(tetri_width);
				ft_memset(row[tetri_height], fill, tetri_width);
				tetri_width = 0;
				tetri_height++;
			}
			raw_shape++;
		}
		new->shape = row;
		new->width = max_wh[0];
		new->height = max_wh[1];
	}
	return (new);
}
