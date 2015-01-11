/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:26:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/11 21:50:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = NULL;
	av = av;
	if (ac == 2)
	{
		get_data();
		init_env(&fdf);
		mlx_key_hook(fdf->win, keyRelease_hook, fdf);
		mlx_hook(fdf->win, KeyPress, KeyPressMask, keyPress_hook, fdf);
		mlx_loop_hook(fdf->mlx, loop_hook, fdf);
//		mlx_expose_hook(fdf->win, expose_hook, fdf);
		mlx_loop(fdf->mlx);
		destroy_env(fdf);
	}
	else if (ac > 2)
		ft_putendl("Cant handle many files");
	else
		ft_putendl("Please give us file name");
	return (0);
}
