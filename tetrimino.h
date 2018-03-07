/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:29:46 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/06 16:47:22 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
#define TETRIMINO_H
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# include <string.h>
# include "points.h"
# include "square.h"

typedef struct	s_tetri
{
	char		**shape;
	t_point		*start;
	int			width;
	int			height;
}				t_tetri;
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
char	**place_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point);
char	**remove_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point);

/* STATIC FUNCTIONS TO BE REMOVED LATER */
int		xy_to_len(int x, int y);
int		validate_block(const char *shape, int len);
int		validate_tetrimino(const char *shape, t_point ***points);
char	**create_tetrimno_shape(int height, int width);
void	fill_tetrimino(const char *raw_shape, const char fill, t_tetri *new);
void	free_tetrimino(t_tetri **tetri);
int		xy_to_len(int x, int y);
t_list	*lstnew_tetri(const char *str, char fill);

/* END STATIC -- TODO: REMOVE LATER */
#endif
