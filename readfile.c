/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:42:53 by enennige          #+#    #+#             */
/*   Updated: 2018/03/04 13:34:46 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// delete and replace this with fillit header

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

// end delete

int	check_file_opened(int fd)
{
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int	close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int	validate_input(char *tetrimino_str, int tetrimino_size)
{
	// need to add more checks here !
	if (tetrimino_str[tetrimino_size] != '\n')
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int check_tetrimino_count(int count)
{
	if (count > 26 || count < 1)
	{
		return (1);
	}
	return (0);
}

// change return to t_list
t_list	*read_tetriminoes(int fd, char *tetrimino_str,
					int tetrimino_size)
{
	int ret;
	int tetrimino_count;

	tetrimino_count = 0;	
	while ((ret = read(fd, tetrimino_str, (tetrimino_size + 1))))
	{
		if (validate_input(tetrimino_str, tetrimino_size) != 1)
		{
			tetrimino_count++;
			// change this part, to make the tetriminos
			ft_putstr("\n**NEXT**\n");
			ft_putstr(tetrimino_str);
			// end change to make linked list
			free(tetrimino_str);
			tetrimino_str = ft_strnew(tetrimino_size + 1);
		}
		if (check_tetrimino_count(tetrimino_count) == 1)
		{
			return (NULL);
		}
	}
	// change to return linked list
	return (NULL);
}

/*
** The read tetriminoes function reads one tetrimino block at a time
*/
int	get_tetriminoes_from_file(char *filename)
{
	int		fd;
	int		tetrimino_size = 20;
	char	*tetrimino_str;

	tetrimino_str = ft_strnew(tetrimino_size + 1);
	if (tetrimino_str)
	{
		fd = open(filename, O_RDONLY);
		if (check_file_opened(fd) == 1)
			return (1);
		read_tetriminoes(fd, tetrimino_str, tetrimino_size);
		if (close_file(fd) == 1)
			return(1);
	}
	return (0);
}
