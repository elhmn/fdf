/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:27:49 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 21:18:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

/*
** Algo incrementale algo de bresenham
*/

static t_draw	*init_d(t_draw *d, t_pos a, t_pos b, t_color *col)
{
	if (!d)
		if (!(d = (t_draw*)malloc(sizeof(t_draw))))
			check_errors(MALLOC, "draw_line.c", "d");
	d->dx = abs(b.x - a.x);
	d->dy = abs(b.y - a.y);
	d->incx = (b.x < a.x) ? -1 : 1;
	d->incy = (b.y < a.y) ? -1 : 1;
	d->ex = 2 * d->dx;
	d->ey = 2 * d->dy;
	d->color = col;
	return (d);
}

static void		draw_1(t_fdf *fdf, t_pos a, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->ey - d->dx;
	pixel_put_img(fdf, a.x, a.y, d->color);
	while (i < d->dx)
	{
		if (fun_choice < 0)
			fun_choice += d->ey;
		else
		{
			fun_choice += d->ey - d->ex;
			a.y += d->incy;
		}
		a.x += d->incx;
		i++;
		pixel_put_img(fdf, a.x, a.y, d->color);
	}
}

static void		draw_2(t_fdf *fdf, t_pos a, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->ex - d->dy;
	pixel_put_img(fdf, a.x, a.y, d->color);
	while (i < d->dy)
	{
		if (fun_choice < 0)
			fun_choice += d->ex;
		else
		{
			fun_choice += d->ex - d->ey;
			a.x += d->incx;
		}
		a.y += d->incy;
		i++;
		pixel_put_img(fdf, a.x, a.y, d->color);
	}
}

void			draw_line(t_fdf *fdf, t_pos a, t_pos b, t_color *color)
{
	t_draw	*d;

	d = init_d(NULL, a, b, color);
	if (d->dx > d->dy)
		draw_1(fdf, a, d);
	else
		draw_2(fdf, a, d);
}
