/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:29:46 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/04 11:47:36 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
#define TETRIMINO_H
# define BLOCK '#'
# define EMTPY '.'
# define NEWLINE '\n'
# include <string.h>

typedef struct	s_tetri
{
	char		**shape;
	int			width;
	int			height;
}				t_tetri;

t_tetri *create_tetrimno(const char *raw_shape, const char fill);
#endif
