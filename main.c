/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 21:50:18 by bmbarga           #+#    #+#             */
/*   Updated: 2014/01/14 01:45:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
** projet incomplet et pas a la norme
*/

void	file_open(int *fd, char *str)
{
	if ((*fd = open(str, O_RDONLY)) < 0)
	{
		perror("");
		exit(0);
	}
}

int		get_next_line_aux(char **len, int fd)
{
	int		ret;

	if ((ret = get_next_line(fd, len)) == -1)
	{
		perror("");
		exit(0);
	}
	return (ret);
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
	pos_init(&mark->k, mark->o.x - UNIT, mark->o.y + UNIT);
	pos_init(&mark->j, mark->o.x + 1, mark->o.y - 4);//j = i vect_product j penser a le calculer proprement
	mlx_pixel_put(e.mlx, e.win, mark->i.x, mark->i.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->j.x, mark->j.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->k.x, mark->k.y, WHITE);
	mlx_pixel_put(e.mlx, e.win, mark->o.x, mark->o.y, WHITE);
	ft_draw_line(e, mark->i, mark->o, RED);
	ft_draw_line(e, mark->j, mark->o, YELLOW);
	ft_draw_line(e, mark->k, mark->o, GREEN);
}

void	ft_printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
	{
		ft_putstr(map[i]);
		ft_putstr("  ");
		i++;
	}
}

void	ft_fdf(t_env e, int fd)
{
	t_mark		mark;
	char		***map;
	char		**map_tmp;
	char		*str;
	char		*tmp;
	int			i;
	int			n_line;
	t_pos		**fdf;
	int			x_len;
	int		x = 0;
	int		z = 0;

	i = 0;
	n_line = 0;
	x_len = 0;
	str = ft_strnew(0);
	ft_setmark(e, &mark);
	while (get_next_line_aux(&tmp, fd))
	{
		str = ft_strjoin(str, ft_strcat(tmp, "\n"));
		n_line++;
	}
	map = (char***) malloc(sizeof(char**) *  (n_line));
	map_tmp = ft_strsplit(str, '\n');
	while (map_tmp[i])
	{
		*(map + i) = ft_strsplit(*(map_tmp + i), ' ');
		i++;
	}
	while (map[z][x])
	{
		x++;
		x_len++;
	}
	fdf = malloc(sizeof(t_pos*) * (n_line));
	i = 0;
	while (i < n_line)
	{
		*(fdf + i) = malloc(sizeof(t_pos) * (x_len + 1));
		i++;
	}
	while (map[z])
	{	
		x = 0;
		while (map[z][x])
		{
			if (ft_atoi(map[z][x]) > 0)
				ft_pixel_put(e, fdf[z][x] = det_coord(*(map + z), x, z, mark), RED);
			else
				ft_pixel_put(e, fdf[z][x] = det_coord(*(map + z), x, z, mark), WHITE);
			x++;
		}
		z++;
	}
	z = 0;
	while (map[z])
	{
		x = 0;
		while (fdf[z][x].y)//condition d arret a revoir
		{
			//ft_putendl("*********************************\n");
		//	ft_putnbr(fdf[z][x].x);
		//	ft_putendl("");
			if (x != 0)
				ft_draw_line(e, fdf[z][x], fdf[z][x - 1], WHITE);
			if (z != 0)
				ft_draw_line(e, fdf[z][x], fdf[z - 1][x], WHITE);	
			x++;
		}
		z++;
	} 
		ft_putstr(" z == ");
		ft_putnbr(z);
		ft_putendl("");
	z = 0;
/*	while (map[z])
	{	
		x = 0;
		while (map[z][x])
		{
			if (ft_atoi(map[z][x]) > 0)
				ft_pixel_put(e, det_coord(*(map + z), x, z, mark), RED);
			else
				ft_pixel_put(e, det_coord(*(map + z), x, z, mark), WHITE);
			x++;
		}
		z++;
	}
//
	i = 0;
	while (i < n_line - 1)
	{
		ft_printmap(*(map + i));
		ft_putendl("");
		i++;
	}	
	//ft_printmap(11, map_tmp);
	//printf("nbr_de ligne = %d\n", n_line);
	//str = ft_strtrim(str);
	//ft_putstr(str);*/
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
		ft_fdf(e, fd);
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
