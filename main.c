/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:47:02 by enennige          #+#    #+#             */
/*   Updated: 2018/03/08 20:34:49 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solve.h"

/*
** The function print_usage_msg() prints a usage message in case users of the
** program need a prompt on how to use it.
*/

void	print_usage_msg(const char *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage_msg(argv[0]);
		return (1);
	}
	if (!solve(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
