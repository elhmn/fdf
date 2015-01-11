/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:52:37 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/14 01:43:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdio.h>

/*
** algo avec fonction afine pas mal mais lent 
*/

void	ft_draw_line_5(void *mlx, void *win, t_pos A, t_pos B)
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
** algorithme incrementale_2 Methode de Lucas Bon pour tous les tracer et rapide method I
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
** Algo incrementale algo de bresenham
*/

void	ft_draw_line(t_env e, t_pos A, t_pos B, int	color)
{
	int		fun_choice;
	int		Ex;
	int		Ey;
	int		i;
	int		incx;
	int		incy;
	int		dx;
	int		dy;

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
		mlx_pixel_put(e.mlx, e.win, A.x, A.y, color);
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
			mlx_pixel_put(e.mlx, e.win, A.x, A.y, color);
		}
	}
	else
	{
		fun_choice = Ex - dy;
		mlx_pixel_put(e.mlx, e.win, A.x, A.y, color);
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
			mlx_pixel_put(e.mlx, e.win, A.x, A.y, color);
		}
	}
}