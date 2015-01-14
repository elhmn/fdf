/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/14 01:45:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.c"

void		pixel_put_img(char *image, int x, int y, t_color *col, t_lay lay)
{
	t_uint		size;

	if (col && image)
	{
		size = lay.line;
		if (size > 0 && x < WIDTH * (lay.bpp / 8))
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}

static void	join_points(t_fdf *fdf, t_lay lay)
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
			pixel_put_img(fdf->img, tab[i][j].pos.x, tab[i][j].pos.y, lay);
		}
	}
}

void		draw_fdf(t_fdf *fdf)
{
	char	*img;
	t_lay	lay;

	if (fdf->bg)
		mlx_destroy_image(fdf->mlx, fdf->bg);
	if (!(fdf->bg = mlx_new_image(tmp->mlx, WIDTH, HEIGH)))
		check_errors(MALLOC, "init_env.c", "tmp->bg");
	mlx_get_data_addr(fdf->bg, &(lay.bpp), &(lay.line), &(lay.endian));
	join_points(fdf, lay);
	mlx_put_image_to_window(fdf->mlx, );
}
