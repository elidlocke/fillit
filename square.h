/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:51:01 by enennige          #+#    #+#             */
/*   Updated: 2018/03/05 19:43:56 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
#define SQUARE_H
# include <string.h>

typedef struct	s_square
{
	int 		size;
	char		**str_array;
}				t_square;

char		**make_square_str(size_t size);
t_square	*make_square_struct(size_t size);
void		print_str_square(char	**square);
#endif
