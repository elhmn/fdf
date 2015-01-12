# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 22:02:30 by bmbarga           #+#    #+#              #
#    Updated: 2015/01/12 00:53:28 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = fdf

SRC = main.c tools.c ft_draw.c

#OBJ = $($(SRC): .c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./includes/ -I /usr/X11/includes/X11/

LIB42 = -L./libft -lft -L /usr/X11/lib -lmlx -lX11 -lXext
LIB = -L./libft -lft -L /usr/lib64/X11 -lm -lmlx -lX11 -lXext

all: $(SRC)
	make -C libft
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB)

42: $(SRC)
	make -C libft
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB42)

#clean:
#	rm -f 
re : all
