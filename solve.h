/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:07:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/08 20:58:23 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "read.h"
# include "tetrimino.h"
# include "square.h"

void	print_usage_msg(const char *prog_name);
int		solve(const char *filename);
int		get_next_point(t_point **point, char **square);
int		solve_a_square(t_square *square, t_list **block);

#endif
