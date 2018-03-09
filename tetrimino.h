/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:29:46 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/09 14:27:39 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
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
t_list			*lstnew_tetri(const char *str, char fill);
char			**create_tetrimno_shape(int height, int width);
void			place_a_tetrimino(t_tetri *tetrimino, t_square *square,
									t_point *point);
void			remove_a_tetrimino(t_tetri *tetrimino, t_square *square);
void			lstdel_tetri(void *content, size_t content_size);
void			free_tetrimino(t_tetri **tetri);
int				validate_tetrimino(const char *shape, t_point ***points);
int				lstadd_tetri(t_list **head, t_list **tail, char *t_str,
							int t_count);
int				check_tetrimino_fits(t_tetri *tetrimino, t_square *square,
									t_point *point);
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
#endif
