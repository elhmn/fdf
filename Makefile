## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2014/01/11 05:56:56 by elhmn             #+#    #+#             ##
##   Updated: 2014/01/11 05:56:56 by elhmn            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

SRC = main.c

FLAGS = -Wall -Wextra -Werror 

CC = gcc

LIB = -L /usr/lib64/X11/ -lmlx -lX11 -lXext

INCLUDE = -I /usr/include/X11 

all: $(SRC)
	$(CC) $(FLAGS) $(INCLUDE) $(SRC) $(LIB)
