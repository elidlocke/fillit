/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:51:01 by enennige          #+#    #+#             */
/*   Updated: 2018/03/06 21:31:57 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
#define SQUARE_H
# include <string.h>

typedef struct	s_square
{
	size_t 		size;
	char		**rows;
}				t_square;

char		**make_square_str(size_t size);
t_square	*create_square(size_t size);
void		print_str_square(char	**square);
void		free_square(t_square **square);
#endif
