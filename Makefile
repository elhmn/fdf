# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 22:02:30 by bmbarga           #+#    #+#              #
#    Updated: 2014/01/12 22:15:10 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = fdf

SRC = main.c tools.c ft_draw.c

#OBJ = $($(SRC): .c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./includes/

LIB = -L./libft -lft -L /usr/X11/lib -lmlx -lX11 -lXext

all: $(SRC)
	make -C libft
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB)

#clean:
#	rm -f 
re : all
