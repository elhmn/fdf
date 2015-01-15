/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:27:49 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 04:13:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

/*
** Algo incrementale algo de bresenham
*/

static t_draw	*init_d(t_draw *d, t_pos A, t_pos B, t_color *col)
{
	if (!d)
		if (!(d = (t_draw*)malloc(sizeof(t_draw))))
			check_errors(MALLOC, "draw_line.c", "d");
	d->dx = abs(B.x - A.x);
	d->dy = abs(B.y - A.y);
	d->incx = (B.x < A.x) ? -1 : 1;
	d->incy = (B.y < A.y) ? -1 : 1;
	d->Ex = 2 * d->dx;
	d->Ey = 2 * d->dy;
	d->color = col;
	return (d);
}

static void		draw_1(t_fdf *fdf, t_pos A, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->Ey - d->dx;
	pixel_put_img(fdf, A.x, A.y, d->color);
	while (i < d->dx)
	{
		if (fun_choice < 0)
			fun_choice += d->Ey;
		else
		{
			fun_choice += d->Ey - d->Ex;
			A.y += d->incy;
		}
		A.x += d->incx;
		i++;
		pixel_put_img(fdf, A.x, A.y, d->color);
	}
}

static void		draw_2(t_fdf *fdf, t_pos A, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->Ex - d->dy;
	pixel_put_img(fdf, A.x, A.y, d->color);
	while (i < d->dy)
	{
		if (fun_choice < 0)
			fun_choice += d->Ex;
		else
		{
			fun_choice += d->Ex - d->Ey;
			A.x += d->incx;
		}
		A.y += d->incy;
		i++;
		pixel_put_img(fdf, A.x, A.y, d->color);
	}
}

void			draw_line(t_fdf *fdf, t_pos A, t_pos B, t_color	*color)
{
	t_draw 	*d;	

	d = init_d(NULL, A, B, color);
	if (d->dx > d->dy)
		draw_1(fdf, A, d);
	else
		draw_2(fdf, A, d);
}
