/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:55:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 13:53:13 by bmbarga          ###   ########.fr       */
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
//	printf("Key = [%d]\n", key); /****************/
	return (0);
}

int		keyPress_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf = fdf;
	key = key;
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
		draw_fdf(fdf);
		fdf->refresh = 0;
	}
	return (0);
}
