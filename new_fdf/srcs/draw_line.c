/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:27:49 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/14 13:43:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

/*
** Algo incrementale algo de bresenham
*/

void	draw_line(t_fdf *fdf, t_pos A, t_pos B, t_color	*color, char *img, t_lay lay)
{
	int		fun_choice;
	int		Ex;
	int		Ey;
	int		i;
	int		incx;
	int		incy;
	int		dx;
	int		dy;

	fdf = fdf; /******* TO CHANGE ********/
	dx = abs(B.x - A.x);
	dy = abs(B.y - A.y);
	incx = (B.x < A.x) ? -1 : 1;
	incy = (B.y < A.y) ? -1 : 1;
	Ex = 2 * dx;
	Ey = 2 * dy;
	i = 0;
	if (dx > dy)
	{
		fun_choice = Ey - dx;
		pixel_put_img(img, A.x, A.y, color, lay);
		while (i < dx)
		{
			if (fun_choice < 0)
				fun_choice += Ey;
			else
			{
				fun_choice += Ey - Ex;
				A.y += incy;
			}
			A.x += incx;
			i++;
			pixel_put_img(img, A.x, A.y, color, lay);
			//usleep(1);
		//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
		}
	}
	else
	{
		fun_choice = Ex - dy;
		pixel_put_img(img, A.x, A.y, color, lay);
		while (i < dy)
		{
			if (fun_choice < 0)
				fun_choice += Ex;
			else
			{
				fun_choice += Ex - Ey;
				A.x += incx;
			}
			A.y += incy;
			i++;
		//	usleep(1);
		//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
			pixel_put_img(img, A.x, A.y, color, lay);
		}
	}
}
