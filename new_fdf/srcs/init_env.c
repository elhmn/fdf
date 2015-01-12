/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/12 08:47:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

void	init_env(t_fdf **fdf)
{
	t_fdf	*tmp;

	if (!fdf || !*fdf)
		if (!(*fdf = (t_fdf*)malloc(sizeof(t_fdf))))
			check_errors(MALLOC, "main.c", "fdf");
	tmp = *fdf;
	if (!(tmp->mlx = mlx_init()))
		check_errors(MALLOC, "init_env.c", "tmp->mlx");
	if (!(tmp->win = mlx_new_window(tmp->mlx, WIDTH, HEIGH, "tmp")))
		check_errors(MALLOC, "init_env.c", "tmp->win");
	if (!(tmp->bg = mlx_new_image(tmp->mlx, WIDTH, HEIGH)))
		check_errors(MALLOC, "init_env.c", "tmp->bg");
	tmp->refresh = 1;
	tmp->map = NULL;
}
