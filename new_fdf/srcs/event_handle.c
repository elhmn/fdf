/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:55:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/17 03:37:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
//#include <stdio.h> /********************/

int		keyRelease_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == ESCAPE)
	{
		destroy_env(fdf);
		exit(0);
	}
	else if (key == 65361)
	{
		fdf->axe = 0;
		fdf->velx = 0;
	}
	else if (key == 65363)
	{
		fdf->axe = 0;
		fdf->velx = 0;
	}
	else if (key == 65364)
	{
		fdf->axe = 0;
		fdf->vely = 0;
	}
	else if (key == 65362)
	{
		fdf->axe = 0;
		fdf->vely = 0;
	}
	printf("Key = [%d]\n", key); /****************/
	return (0);
}

int		keyPress_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf = fdf;
	if (key == 65361)
	{
		fdf->axe = X;
		fdf->velx = -1;
	}
	else if (key == 65363)
	{
		fdf->axe = X;
		fdf->velx= 1;
	}
	else if (key == 65364)
	{
		fdf->axe = Y;
		fdf->vely = 1;
	}
	else if (key == 65362)
	{
		fdf->axe = Y;
		fdf->vely = -1;
	}
//	printf("Key = [%d]\n", key); /***************/
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
		update_tab(fdf);
		draw_fdf(fdf);
		fdf->refresh = 0;
	}
	if (fdf->axe)
	{
//		move_axis(&(fdf->base), fdf->axe, fdf->vel);
		update_pt(fdf);
		fdf->refresh = 1;
	}
	return (0);
}
