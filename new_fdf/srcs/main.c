/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:26:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 21:27:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (ac == 2)
	{
		init_env(&fdf);
		get_data(fdf, av[1]);
		init_mlx(fdf);
		mlx_key_hook(fdf->win, keyrelease_hook, fdf);
		mlx_hook(fdf->win, KeyPress, KeyPressMask, keypress_hook, fdf);
		mlx_loop_hook(fdf->mlx, loop_hook, fdf);
		mlx_expose_hook(fdf->win, expose_hook, fdf);
		mlx_loop(fdf->mlx);
		destroy_env(fdf);
	}
	else if (ac > 2)
		ft_putendl("Cant handle many files");
	else
		ft_putendl("Please give us file name");
	return (0);
}
