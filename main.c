/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 21:50:18 by bmbarga           #+#    #+#             */
/*   Updated: 2014/01/13 02:58:24 by bmbarga          ###   ########.fr       */
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

void	ft_setmark(t_env e, t_mark *mark)
{
	pos_init(&mark->o, 250, 250);
	pos_init(&mark->i, mark->o.x + UNIT, mark->o.y);
	pos_init(&mark->j, mark->o.x - UNIT, mark->o.y + UNIT);//j = i vect_product j penser a le calculer proprement
	pos_init(&mark->k, mark->o.x, mark->o.y - UNIT);
	mlx_pixel_put(e.mlx, e.win, mark->i.x, mark->i.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->j.x, mark->j.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->k.x, mark->k.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->o.x, mark->o.y, WHITE);
	ft_draw_line(e, mark->i, mark->o, RED);
	ft_draw_line(e, mark->j, mark->o, YELLOW);
	ft_draw_line(e, mark->k, mark->o, GREEN);
}

void	ft_fdf(t_env e)
{
	t_mark		mark;

	ft_setmark(e, &mark);	
}

int		main(int argc, char **argv)
{
	int			fd;
	t_env		e;
	
	if (argc == 2)
	{
		file_open(&fd, *(argv + 1));
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 800, 600, "FDF");
		ft_fdf(e);
		sleep(60);
		mlx_destroy_window(e.mlx, e.win);
		close(fd);
	}
	else
	{
		ft_putendl("no file name");
	}
	return (0);
}
