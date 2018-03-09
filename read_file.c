/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <enennige@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:42:53 by enennige          #+#    #+#             */
/*   Updated: 2018/03/08 19:54:19 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read.h"
#include "tetrimino.h"

/*
** Checks the formatting of the input tetrimino for newline characters. Flips
** the value of ends_in_newline depending on whether the tetrimino ends in a
** newline or not
*/

int		validate_newlines(char *tetrimino_str, int *ends_in_newline)
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
	if (tetrimino_str[TETRI_SIZE] != '\0')
		*ends_in_newline = 1;
	else
		*ends_in_newline = 0;
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
** creates a new linked list element for a tetrimino
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

/*
** Frees a list of tetriminoes
*/

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

/*
** The function lstadd_tetri() adds a tetrimino to the tlist of tetriminoes,
** assigning the correct letter for the tetriminoes' order.
*/

int		lstadd_tetri(t_list **head, t_list **tail, char *t_str, int t_count)
{
	if (t_count && ((*tail)->next =
		lstnew_tetri(t_str, 'A' + t_count)))
		*tail = (*tail)->next;
	else if ((*head = lstnew_tetri(t_str, 'A' + t_count)))
		*tail = *head;
	else
	{
		ft_lstdel(head, &lstdel_tetri);
		return (-1);
	}
	return (0);
}

/*
** Reads the tetriminoes from a file that has already been opened, adding them
** to a linked list as it goes
*/

t_list	*read_tetriminoes(int fd, int *tetri_cnt)
{
	char	*tetrimino_str;
	int		ends_in_newline;
	t_list	*tail;
	t_list	*head;

	tetrimino_str = ft_strnew(TETRI_SIZE + 1);
	while (read(fd, tetrimino_str, (TETRI_SIZE + 1)))
	{
		if (validate_newlines(tetrimino_str, &ends_in_newline) == -1 ||
			check_tetrimino_count(*tetri_cnt + 1) == -1)
			return (NULL);
		tetrimino_str[TETRI_SIZE] = '\0';
		if (lstadd_tetri(&head, &tail, tetrimino_str, *tetri_cnt) == -1)
			return (NULL);
		ft_bzero(tetrimino_str, TETRI_SIZE + 1);
		(*tetri_cnt)++;
	}
	ft_strdel(&tetrimino_str);
	if ((*tetri_cnt) == 0 || ends_in_newline == 1)
		return (NULL);
	return (head);
}

/*
** Takes in a file, opens it, reads the file, gets the tetriminoes
** and returns them in a linked list.
*/

t_list	*get_tetriminoes_from_file(const char *filename, int *tetri_cnt)
{
	int		fd;
	t_list	*tetri_lst;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (!(tetri_lst = read_tetriminoes(fd, tetri_cnt)))
	{
		close(fd);
		return (NULL);
	}
	if ((close(fd) == -1))
		return (NULL);
	return (tetri_lst);
}
