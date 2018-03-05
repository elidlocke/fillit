/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:29:46 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/04 18:09:24 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
#define TETRIMINO_H
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# include <string.h>

typedef struct	s_point
{
	int 		x;
	int			y;
}				t_point;
typedef struct	s_tetri
{
	char		**shape;
	int			width;
	int			height;
}				t_tetri;
t_tetri *create_tetrimno(const char *raw_shape, const char fill);
t_point *create_point(int len);
#endif
