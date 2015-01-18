/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:55:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 19:20:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

int		keyrelease_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == K_ESCAPE)
	{
		destroy_env(fdf);
		exit(0);
	}
	else if (key == K_LEFT)
	{
		fdf->axe = 0;
		fdf->velx = 0;
	}
	else if (key == K_RIGHT)
	{
		fdf->axe = 0;
		fdf->velx = 0;
	}
	else if (key == K_DOWN)
	{
		fdf->axe = 0;
		fdf->vely = 0;
	}
	else if (key == K_UP)
	{
		fdf->axe = 0;
		fdf->vely = 0;
	}
	else if (key == K_ENTER)
	{
		if (fdf->move == MOVE)
			fdf->move = MOVEA;
		else if (fdf->move == MOVEA)
			fdf->move = MOVE;
	}
	else if (key == K_PLUS)
	{
		scale_plus(fdf, 2);
		fdf->refresh = 1;;
	}
	else if (key == K_MOINS)
	{
		scale_moins(fdf, 2);
		fdf->refresh = 1;;
	}
	return (0);
}

int		keypress_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf = fdf;
	if (key == K_LEFT)
	{
		fdf->axe = X;
		fdf->velx = -1;
	}
	else if (key == K_RIGHT)
	{
		fdf->axe = X;
		fdf->velx= 1;
	}
	else if (key == K_DOWN)
	{
		fdf->axe = Y;
		fdf->vely = 1;
	}
	else if (key == K_UP)
	{
		fdf->axe = Y;
		fdf->vely = -1;
	}
	return (0);
}

int		expose_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (fdf->bg)
	{
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bg, 0, 0);
		fdf->refresh = 1;
	}
	else
	{
		draw_fdf(fdf);
		fdf->refresh = 0;
	}
	return (0);
}

int		loop_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (void*)param;
	if (fdf->refresh)
	{
		draw_fdf(fdf);
		fdf->refresh = 0;
	}
	if (fdf->axe)
	{
		update_pt(fdf);
		fdf->refresh = 1;
	}
	return (0);
}
