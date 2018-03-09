# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpollore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 08:52:07 by jpollore          #+#    #+#              #
#    Updated: 2018/03/09 15:47:02 by jpollore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
LIB_NAME = libft.a
CS = main.c read_file.c tetrimino.c points.c place_tetrimino.c square.c
CS += solve.c lst_util.c tetri_utils.c
CFLAGS = -Wall -Wextra -Werror
LIB_OPT = -L./libft -lft
OBJS = $(patsubst %.c, %.o, $(CS))
OPTION1 = -I. -I./libft/includes

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) $(OPTION1) -c $(CS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

fclean_lib:
	make fclean -C libft/

re: fclean_lib fclean all
