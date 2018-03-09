/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:24:35 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/08 20:55:26 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TETRI_SIZE 20

t_list		*get_tetriminoes_from_file(const char *filename);
#endif
