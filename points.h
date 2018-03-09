/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:25:07 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/08 20:56:18 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H
# include <string.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
t_point			*create_point(int len);
t_point			*create_point_fromxy(int x, int y);
void			free_point(t_point **point);
void			free_minmax_points(t_point ***points);
#endif
