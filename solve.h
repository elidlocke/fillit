/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:07:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/07 11:24:59 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
#define SOLVE_H
# include "read.h"

void	print_usage_msg(const char *prog_name);
int		solve(const char *filename);
int		get_next_point(t_point **point, char **square);
#endif
