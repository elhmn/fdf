/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:55:17 by bmbarga           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/13 19:13:06 by bmbarga          ###   ########.fr       */
=======
/*   Updated: 2015/01/13 14:24:48 by bmbarga          ###   ########.fr       */
>>>>>>> 4ac5663dc54ca011e8088e3f4db1868021857bf1
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

	if (!(fdf->bg = mlx_new_image(tmp->mlx, WIDTH, HEIGH)))
		check_errors(MALLOC, "init_env.c", "tmp->bg");
int		loop_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (void*)param;
	if (fdf->refresh)
	{
//		placer les points
//		tracer
//		ft_putendl("je suis con"); /*****************/
//		clear image
//		put image on window
		fdf->refresh = 0;
	}
	return (0);
}
