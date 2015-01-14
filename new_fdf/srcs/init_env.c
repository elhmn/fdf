/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/14 03:37:01 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

static void		init_base(t_base *base)
{
	if (base)
	{
		base->o.pt.x = 0;
		base->o.pt.y = 0;
		base->o.pt.z = 0;
		base->o.pos.x = O_X;
		base->o.pos.y = O_Y;
		base->i.pt.x = 1;
		base->i.pt.y = 0;
		base->i.pt.z = 0;
		base->i.pos.x = I_X;
		base->i.pos.y = I_Y;
		base->j.pt.x = 0;
		base->j.pt.y = 1;
		base->j.pt.z = 0;
		base->j.pos.x = J_X;
		base->j.pos.y = J_Y;
		base->k.pt.x = 0;
		base->k.pt.y = 0;
		base->k.pt.z = 1;
		base->k.pos.x = K_X;
		base->k.pos.y = K_Y;
	}
}

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
	tmp->refresh = 1;
	tmp->tab = NULL;
	tmp->tab_h = 0;
	tmp->bg = NULL;
	init_base(&(tmp->base));
}
