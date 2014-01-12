/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 21:50:18 by bmbarga           #+#    #+#             */
/*   Updated: 2014/01/13 00:12:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	file_open(int *fd, char *str)
{
	if ((*fd = open(str, O_RDONLY)) < 0)
	{
		perror("");
		exit(0);
	}
}

/*
void	vect_init(t_vect *pt, int x, int y, int z)
{
		vect->x = x;
		vect->y = y;
		vect->z = z;
}
*/

int		main(void/*int argc, char **argv*/)
{
	//int			fd;
	void		*win;
	void		*mlx;
	t_mark		mark;

	pos_init(&mark.o, 100, 100);
	pos_init(&mark.i, mark.o.x + UNIT, mark.o.y);
	pos_init(&mark.j, mark.o.x - UNIT, mark.o.y + UNIT);
	pos_init(&mark.k, mark.o.x, mark.o.y - UNIT);

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "FDF");
	mlx_pixel_put(mlx, win, mark.i.x, mark.i.y, 0xFFFFFF);
	mlx_pixel_put(mlx, win, mark.j.x, mark.j.y, 0xFFFFFF);
	mlx_pixel_put(mlx, win, mark.k.x, mark.k.y, 0xFFFFFF);
	mlx_pixel_put(mlx, win, mark.o.x, mark.o.y, 0xFFFFFF);
	sleep(60);
	mlx_destroy_window(mlx, win);
	/*if (argc == 2)
	{
		file_open(&fd, *(argv + 1));

		close(fd);
	}
	else
	{
		ft_putendl("no file name");
	}
	*/
	return (0);
}
