# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpollore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 08:52:07 by jpollore          #+#    #+#              #
#    Updated: 2018/03/04 08:59:31 by jpollore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
LIB_NAME = libft.a
CS = main.c
OPTION = -Wall -Wextra -Werror
LIB_OPT = -L. -lft
OBJS = $(patsubst %.c, %.o, $(CS))

all: $(NAME)

$(NAME): $(LIB_NAME)
	$(CC) $(OPTION) $(LIB_OPT) $(CS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
