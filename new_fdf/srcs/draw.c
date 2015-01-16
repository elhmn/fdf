/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/16 12:59:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "debug.h"
#include "check_errors.h"

void		pixel_put_img(t_fdf *fdf, int x, int y, t_color *col)
{
	int		size;
	char	*image;
	t_lay	lay;
	int		b;

	lay = *(fdf->lay);
	image = fdf->img;
	if (col && image)
	{
		size = lay.line;
		b = lay.bpp / 8;
		x *= b;
		if (size > 0 && (y < fdf->heigh && y >= 0) && (x >= 0 && x + lay.bpp / 8 < lay.line))
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}

static	int	w_tab(t_coord *tab)
{
	int		w;

	w = 0;
	while (tab[w].end)
		w++;
	return (w);
}

int			altitude(int alt)
{
	if (alt >= 0 && alt < 5)
		return (DWN);
	if (alt >= 0 && alt < 10)
		return (MIDWN);
	if (alt >= 10 && alt < 15)
		return (MIUP);
	if (alt >= 15 && alt < 20)
		return (UP);
	if (alt > 20)
		return (UPPER);
	return (0);
}

void		choose_color(t_fdf *fdf, t_coord **tab, int i, int j)
{
	int		alt;

	alt = altitude(tab[i][j].pt.y);
	if (alt == DWN)
	{
		fdf->white = init_color(NULL, DWN);
	}
	else if (alt == MIDWN)
	{
		fdf->white = init_color(NULL, MIDWN);
	}
	else if (alt == MIUP)
	{
		fdf->white = init_color(NULL, MIUP);
	}
	else if (alt == UP)
	{
		fdf->white = init_color(NULL, UP);
	}
	else if (alt == UPPER)
	{
		fdf->white = init_color(NULL, UPPER);
	}
}

static void	join_points(t_fdf *fdf)
{
	t_coord **tab;
	int		i;
	int		j;

	i = -1;
	tab = fdf->tab;
	while (++i < fdf->tab_h)
	{
		j = -1;
		while (tab[i][++j].end)
		{
			if (i + 1 < fdf->tab_h && j < w_tab(tab[i + 1]))
			{
				choose_color(fdf, tab, i + 1, j);
				draw_line(fdf, tab[i][j].pos, tab[i + 1][j].pos, fdf->white);
			}
			if (tab[i][j + 1].end)
			{
				choose_color(fdf, tab, i, j + 1);
				draw_line(fdf, tab[i][j].pos, tab[i][j + 1].pos, fdf->white);
			}
		}
	}
}

void		draw_fdf(t_fdf *fdf)
{
	if (fdf->bg)
		mlx_destroy_image(fdf->mlx, fdf->bg);
	if (!(fdf->bg = mlx_new_image(fdf->mlx, fdf->width, fdf->heigh)))
		check_errors(MALLOC, "fdf->bg", "draw.c");
	fdf->img = mlx_get_data_addr(fdf->bg, &(fdf->lay->bpp), &(fdf->lay->line), &(fdf->lay->endian));
	if (!fdf->img)
		check_errors(MALLOC, "img", "draw.c");
	join_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
}
