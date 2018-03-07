/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:24:32 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/07 09:31:39 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"

t_point		*create_point(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = ((len + 5) / 5);
		if (point->y > 0)
			point->y -= 1;
	}
	return (point);
}

void		free_point(t_point **point)
{
	if (!point)
		return ;
	free(*point);
	*point = NULL;
}

void		free_minmax_points(t_point ***points)
{
	if (!points)
		return ;
	free_point(*points + 1);
	free_point(*points);
	free(*points);
	*points = NULL;
}

/*
** Make a point, based on an x and y coordinate
*/
t_point		*create_point_fromxy(int x, int y)
{
	t_point *point;
	point = (t_point *)ft_memalloc(sizeof(*point));
	if (point)
	{
		point->x = x;
		point->y = y;
		return (point);
	}
	return (NULL);
}
