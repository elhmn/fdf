/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:26:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 06:44:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"

static void		init_mlx(t_fdf *fdf)
{
	if (fdf)
	{
		if (!(fdf->mlx = mlx_init()))
				check_errors(MALLOC, "init_env.c", "tmp->mlx");
		if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGH, "tmp")))
			check_errors(MALLOC, "init_env.c", "fdf->win");
	}
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (ac == 2)
	{
		init_env(&fdf);
		get_data(fdf, av[1]);
		init_mlx(fdf);
		mlx_key_hook(fdf->win, keyRelease_hook, fdf);
		mlx_hook(fdf->win, KeyPress, KeyPressMask, keyPress_hook, fdf);
		mlx_loop_hook(fdf->mlx, loop_hook, fdf);
		mlx_expose_hook(fdf->win, expose_hook, fdf);
		print_type("fdf->tab_w", &(fdf->tab_w), INT);
		print_type("fdf->tab_h", &(fdf->tab_h), INT);
		mlx_loop(fdf->mlx);
//		dont forget to destroy fdf->tab
		destroy_env(fdf);
	}
	else if (ac > 2)
		ft_putendl("Cant handle many files");
	else
		ft_putendl("Please give us file name");
	return (0);
}
