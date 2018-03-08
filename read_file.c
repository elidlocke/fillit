/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:42:53 by enennige          #+#    #+#             */
/*   Updated: 2018/03/08 15:52:16 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read.h"
#include "tetrimino.h"

/*
** Check the formatting of the input tetrimino for newline
** characters. If invalid, print an error message.
*/

int		validate_newlines(char *tetrimino_str)
{
	int newline_placement;

	newline_placement = TETRI_SIZE - 1;
	while (newline_placement > 0)
	{
		if (tetrimino_str[newline_placement] != '\n')
			return (-1);
		newline_placement = newline_placement - 5;
	}
	if (tetrimino_str[TETRI_SIZE] != '\n' && tetrimino_str[TETRI_SIZE] != '\0')
		return (-1);
	return (0);
}

/*
** Checks that the file passed in does not contain more than 26 or
** less than 1 tetrimino.
*/

int		check_tetrimino_count(int count)
{
	if (count > 26 || count < 0)
		return (-1);
	return (0);
}

/*
** Reads a file that has already been opened and if the file
** is valid, returns a t_list with the individual tetriminoes.
*/

t_list	*lstnew_tetri(const char *str, char fill)
{
	t_tetri *tetri;
	t_list	*node;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(node = ft_lstnew((void *)tetri, sizeof(*tetri))))
	{
		free_tetrimino(&tetri);
		return (NULL);
	}
	return (node);
}

void		lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

t_list		*read_tetriminoes(int fd)
{
	int		tetrimino_count;
	char	*tetrimino_str;
	int		ends_in_newline;
	t_list	*tail;
	t_list	*head;

	tetrimino_str = ft_strnew(TETRI_SIZE + 1);
	tetrimino_count = 0;
	while (read(fd, tetrimino_str, (TETRI_SIZE + 1)))
	{
		if (validate_newlines(tetrimino_str) == -1 ||
			check_tetrimino_count(tetrimino_count + 1) == -1)
			return (NULL);
		if (tetrimino_str[TETRI_SIZE] != '\0')
		{
			ends_in_newline = 1;
			tetrimino_str[TETRI_SIZE] = '\0';
		}
		else
			ends_in_newline = 0;
		if (tetrimino_count && (tail->next = lstnew_tetri(tetrimino_str, 'A' + tetrimino_count)))
			tail = tail->next;
		else if ((head = lstnew_tetri(tetrimino_str, 'A' + tetrimino_count)))
			tail = head;
		else
		{
			ft_lstdel(&head, &lstdel_tetri);
			return (NULL);
		}
		ft_bzero(tetrimino_str, TETRI_SIZE + 1);
		tetrimino_count++;
	}
	ft_strdel(&tetrimino_str);
	if (tetrimino_count == 0 || ends_in_newline == 1)
		return (NULL);
	return (head);
}

/*
** Takes in a file, opens it, reads the file, gets the tetriminoes
** and returns them in a linked list.
*/

t_list		*get_tetriminoes_from_file(const char *filename)
{
	int		fd;
	t_list	*tetri_lst;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (!(tetri_lst = read_tetriminoes(fd)))
	{
		close(fd);
		return (NULL);
	}
	if ((close(fd) == -1))
		return (NULL);
	return (tetri_lst);
}
