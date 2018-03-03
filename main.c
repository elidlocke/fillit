/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:47:02 by enennige          #+#    #+#             */
/*   Updated: 2018/03/02 18:02:26 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		is_invalid(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit [input_file]\n");
		return (1);
	}
	//else if add piece for if file is invalid or pieces are invalid
	return (0);
}


int main(int argc, char **argv)
{
	if (is_invalid(argc))
	{
		return(1);
	}
	printf("%s",argv[1]);
}
