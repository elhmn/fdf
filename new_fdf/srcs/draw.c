/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/14 03:36:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include <unistd.h>

void		pixel_put_img(char *image, int x, int y, t_color *col, t_lay lay)
{
	int		size;

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
			print_color(&(fdf->white));
			pixel_put_img(img, tab[i][j].pos.x, tab[i][j].pos.y, &(fdf->white), lay);
		}
	}
}

void		draw_fdf(t_fdf *fdf)
{
	t_lay	lay;
	t_color	col;
	char	*img;

	img = NULL;
	col.color = 0xFFFFFF; /******* A MODIFIER **/
	set_color(&col); /******* A MODIFIER *****/
	fdf->white = col; /****** TO CHANGE ****/
	if (fdf->bg)
		mlx_destroy_image(fdf->mlx, fdf->bg);
	ft_putendl("TEST 3"); /**************/
	if (!(fdf->bg = mlx_new_image(fdf->mlx, WIDTH, HEIGH)))
		check_errors(MALLOC, "fdf->bg", "draw.c");
	ft_putendl("TEST 1"); /**************/
	img = mlx_get_data_addr(fdf->bg, &(lay.bpp), &(lay.line), &(lay.endian));
	if (!img)
		check_errors(MALLOC, "img", "draw.c");
	ft_putendl("TEST"); /**************/
	join_points(fdf, lay, img);
	ft_putendl("TEST 4"); /**************/
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
}
