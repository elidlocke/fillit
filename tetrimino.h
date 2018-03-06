/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:29:46 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/06 14:11:18 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
#define TETRIMINO_H
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# include <string.h>
# include "points.h"

typedef struct	s_tetri
{
	char		**shape;
	t_point		*start;
	int			width;
	int			height;
}				t_tetri;
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);

/* STATIC FUNCTIONS TO BE REMOVED LATER */
int		xy_to_len(int x, int y);
int		validate_block(const char *shape, int len);
int		validate_tetrimino(const char *shape, t_point ***points);
char	**create_tetrimno_shape(int height, int width);
void	fill_tetrimino(const char *raw_shape, const char fill, t_tetri *new);
void	free_tetrimino(t_tetri **tetri);
int		xy_to_len(int x, int y);

/* END STATIC -- TODO: REMOVE LATER */
#endif
