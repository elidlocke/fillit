/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:47:02 by enennige          #+#    #+#             */
/*   Updated: 2018/03/04 13:29:40 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//move this to the header

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_tetriminoes_from_file(char *filename);

//end content to move to header

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
	get_tetriminoes_from_file(argv[1]);
	
	return (0);
}
