/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:47:02 by enennige          #+#    #+#             */
/*   Updated: 2018/03/04 08:57:58 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_usage_msg(char *prog_name)
{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd(prog_name, STDERR_FILENO);
		ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage_msg(argv[0]);
		return (1);
	}
	return (0);
}
