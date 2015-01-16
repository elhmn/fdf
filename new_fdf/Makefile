# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 22:02:30 by bmbarga           #+#    #+#              #
#    Updated: 2015/01/16 15:36:04 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c get_next_line.c check_errors.c fun_err_01.c destroy_env.c \
	  init_env.c event_handle.c get_map.c debug_01.c set_tab.c color.c \
	  draw.c draw_line.c update_tab.c math_ope_01.c

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./includes/ -I /usr/X11/include/X11
INCHOME = -I ./includes/ -I /usr/include/X11

LIB42 = -L./libft -lft -L /usr/X11/lib -lmlx -lX11 -lXext
LIB = -L./libft -lft -L /usr/lib64/X11 -lm -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(INCLUDES) $(SRCS) $(LIB42)

home: $(SRCS)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(INCHOME) $(SRCS) $(LIB)

clean:
	make -C libft clean
fclean:
	make -C libft fclean
	rm  -rf $(NAME)
re : fclean all
