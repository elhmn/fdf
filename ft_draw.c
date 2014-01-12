/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:52:37 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/11 18:52:37 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdio.h>

/*
** algo avec fonction afine pas mal mais lent 
*/

void	ft_draw_line(void *mlx, void *win, t_pos A, t_pos B)
{
	double		a;
	double		b;
	double		dx;
	double		dy;
	int			incx;
	int			incy;
	
	dx = (double) (B.x - A.x);
	dy = (double) (B.y - A.y);
	a = dy / dx;
	b = (double)A.y - a * (double)A.x;
	incx = (A.x < B.x) ? 1 : -1;
	incy = (A.y < B.y) ? 1 : -1;
	if (abs(a) < 1)
	{
		while (A.x != B.x)
		{
			A.y = (int)floor(a * (double)A.x + b);
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFFFFFF);
			A.x += incx;
			usleep(10000);
		}
	}
	 else
	{
		a = dx / dy;
		b = (double)A.x - a * (double)A.y;
		while (A.y != B.y)
		{
			A.x = (int) floor(a * (double)A.y + b);
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFFFFFF);
			A.y += incy;
			usleep(10000);
		}
	}
}

/*
** algorithme ADN (Analyseur differentiel numerique)
** incrementale_1 Bon pour des ecrans a basse resolution
*/

void	ft_draw_line_2(void *mlx, void *win, t_pos A, t_pos B)
{
	int		dx;
	int		dy;
	int		approx;

	dx = B.x - A.x;
	dy = B.y - A.y;
	approx = dx / dy;
	mlx_pixel_put(mlx, win, A.x, A.y, 0xFF0000);
	while (A.x <= B.x)
	{
		approx += dy;
		if (approx >= dx)
		{
			approx -= dx;
			A.y++;
		}
		mlx_pixel_put(mlx, win, A.x, A.y, 0xFF0000);
		usleep(10000);
		A.x++;
	}
}

/*
** Algo incrementale ADN (Analyseur Differentiel Numerique)
*/

static int		MAX(int	a, int b)
{
	int	val;

	val = (a > b) ? a : b;
	return (val);
}

void	ft_draw_line_3(void *mlx, void *win, t_pos A, t_pos B)
{
	double	incx;
	double	incy;
	int		longueur;
	int		i;
	double		x;
	double		y;
	
	i = 0;
	x = A.x + 0.5;
	y = A.y + 0.5;
	longueur = MAX(abs(B.x - A.x), abs(B.y - A.y));
	incx = (double)(B.x - A.x) / (double)longueur;
	incy = (double)(B.y - A.y) / (double)longueur;
	while (i < longueur)
	{
		mlx_pixel_put(mlx, win, (int)x, (int)y, 0xFF0000);
		x += incx;
		y += incy;
		i++;
	}
}

/*
** algorithme incrementale_2 Bon pour tous les tracer et rapide method I
** penser a coder la methode 2 mais aussi et surtout a comprendre parfaitement
** cet algo
*/

void	ft_draw_line_4(void *mlx, void *win, t_pos A, t_pos B)
{
	t_pos	d;
	t_pos	inc;
	int		i;
	float	approx;
	
	i = 1;
	d.x = B.x - A.x;
	d.y = B.y - A.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = abs(d.x);
	d.y = abs(d.y);
	if (d.x >= d.y)
	{
		approx = d.x / 2;
		while (i < d.x)
		{
			A.x += inc.x;
			approx += d.y;
			if (approx >= d.x)
			{
				approx -= d.x;
				A.y += inc.y;
			}
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFFFFFF);
			i++;
		}
	}
	else
	{
		approx = d.y / 2;
		while (i < d.y)
		{
			approx += d.x;
			A.y += inc.y;
			if (approx >= d.y)
			{
				approx -= d.y;
				A.x += inc.x;
			}
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFF0000);
			i++;
		}
	}
}

/*
** Algo incremental_2_2
**
*/

void	ft_draw_line_5(void *mlx, void *win, t_pos A, t_pos B)
{
	float	fun_choice;
	float	xinc;
	float	yinc;
	float		d;
	int		i;
//	int		dx = B.x - A.x;
	t_rect	rect;

	rect.high = 5;
	rect.width = 5;
	int	x = A.x;
	int	y = A.y;
//	if (B.x - A.x > 0 || )
	d = (B.y - A.y) / (B.x - A.x);
	xinc = -2 * d;
	yinc = -2 * d + 2;
	i = 0;
	draw(mlx, win, rect, A);
	draw(mlx, win, rect, B);
	if (d < 1)
	{
		printf("lol\n");
		fun_choice = d * -2 * (2 * A.x + 1) + 3 * A.y + 1;
		while (A.x < B.x)
		{
		fun_choice = d * -2 * (A.x + x + 1) + A.y + y + 1;
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFF0000);
			if (fun_choice > 0)
			{
				printf("fun_choice > 0\n");
		//		fun_choice += xinc;
			}
			else
			{
				printf("fun_choice > 0\n");
		//		fun_choice += yinc;
				A.y++;
			}
			A.x++;
			i++;
		}
	}
	else
	{
		d = (B.x - A.x) / (B.y - A.y);
		fun_choice = d * 2 * A.y + 2 *A.x + 1;
		while (A.y >= B.y)
		{
			printf("lol\n");
			mlx_pixel_put(mlx, win, A.x, A.y, 0xFFFFFF);
			if (fun_choice > 0)
				fun_choice += yinc;
			else
			{
				fun_choice += xinc;
				A.x--;
			}
			A.y--;
		}
	}
}
