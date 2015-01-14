/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/14 09:17:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "debug.h"
#include "check_errors.h"

void		pixel_put_img(char *image, int x, int y, t_color *col, t_lay lay, t_fdf *fdf)
{
	int		size;
	int		i;

	i = 0;
	fdf = fdf; /****************/
	if (col && image)
	{
		size = lay.line;
		print_type("lay.line", &(lay.line), INT);
		print_type("lay.endian", &(lay.endian), INT);
		print_type("lay.bpp", &(lay.bpp), INT);
		print_color(col);
		while (i < 4 && !image[(y * (size)) + x + i])
			i++;
		if (i == 4 && size > 0 && x < WIDTH * (lay.bpp / 8))
		{
//			image[(y * (size)) + x] = mlx_get_color_value(fdf->mlx, col->color);
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}

static void	join_points(t_fdf *fdf, t_lay lay, char *img)
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
			if (i + 1 < fdf->tab_h)
				draw_line(fdf, tab[i][j].pos, tab[i + 1][j].pos, fdf->white, img, lay);
			if (tab[i][j + 1].end)
				draw_line(fdf, tab[i][j].pos, tab[i][j + 1].pos, fdf->white, img, lay);
		}
	}
}

void		draw_fdf(t_fdf *fdf)
{
	t_lay	lay;
	char	*img;

	img = NULL;
	if (fdf->bg)
		mlx_destroy_image(fdf->mlx, fdf->bg);
	if (!(fdf->bg = mlx_new_image(fdf->mlx, WIDTH, HEIGH)))
		check_errors(MALLOC, "fdf->bg", "draw.c");
	img = mlx_get_data_addr(fdf->bg, &(lay.bpp), &(lay.line), &(lay.endian));
	if (!img)
		check_errors(MALLOC, "img", "draw.c");
	join_points(fdf, lay, img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
}
