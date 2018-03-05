/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:42:53 by enennige          #+#    #+#             */
/*   Updated: 2018/03/05 15:50:17 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// delete and replace this with fillit header

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

// end delete

/*
** Check if a file is properly opened. If not, print an error message.
*/
int		check_file_opened(int fd)
{
	if (fd == -1)
	{
		ft_putstr("error: file not opened\n");
		return (1);
	}
	return (0);
}

/*
** Close a file and check if a file is properly closed.
** If not, print an error message.
*/
int		close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("error: file not closed\n");
		return (1);
	}
	return (0);
}

/*
** Check the formatting of the input tetrimino for newline
** characters. If invalid, print an error message.
*/

int		validate_newlines(char *tetrimino_str, int tetrimino_size)
{
	int newline_placement;

	newline_placement = tetrimino_size;
	while ((newline_placement = newline_placement / 5))
	{
		if (tetrimino_str[tetrimino_size - 1] != '\n')
		{
			ft_putstr("error: tetrimino is not 4x4\n");
			return (1);
		}
	}
	if (tetrimino_str[tetrimino_size] != '\n')
	{
		ft_putstr("error: no newline after tetrimino block\n");
		return (1);
	}
	return (0);
}

/*
** Checks that the file passed in does not contain more than 26 or
** less than 1 tetrimino.
*/

int		check_tetrimino_count(int count)
{
	if (count > 26 || count < 0)
	{
		ft_putstr("error: too many, or too few tetriminoes\n");
		return (1);
	}
	return (0);
}

/*
** Reads a file that has already been opened and if the file
** is valid, returns a t_list with the individual tetriminoes.
*/

// note: change return to t_list
t_list		*read_tetriminoes(int fd, char *tetrimino_str, int tetrimino_size)
{
	int ret;
	int tetrimino_count;

	tetrimino_count = 0;
	while ((ret = read(fd, tetrimino_str, (tetrimino_size + 1))))
	{
		if (validate_newlines(tetrimino_str, tetrimino_size) == 1)
		{
			return (NULL);
		}
		tetrimino_count++;
		// change this part, to make the tetriminos
		ft_putstr("\n**NEXT**\n");
		ft_putstr(tetrimino_str);
		// end change to make linked list
		free(tetrimino_str);
		tetrimino_str = ft_strnew(tetrimino_size + 1);
		if (check_tetrimino_count(tetrimino_count) == 1)
		{
			return (NULL);
		}
	}
	// change to return linked list
	return (NULL);
}

/*
** Takes in a file, opens it, reads the file, gets the tetriminoes
** and returns them in a linked list.
*/

//note: change return to linked list
t_list		*get_tetriminoes_from_file(char *filename)
{
	int		fd;
	int		tetrimino_size;
	char	*tetrimino_str;

	tetrimino_size = 20;
	tetrimino_str = ft_strnew(tetrimino_size + 1);
	if (tetrimino_str)
	{
		fd = open(filename, O_RDONLY);
		if (check_file_opened(fd) == 1)
			return (NULL);
		// change call to read_tetriminoes to t_list =
		read_tetriminoes(fd, tetrimino_str, tetrimino_size);
		if (close_file(fd) == 1)
			return (NULL);
	}
	// change to return tetriminoes
	return (NULL);
}
