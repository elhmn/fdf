/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/19 20:27:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"
#include <stdio.h>

static void		init_base(t_fdf *fdf, t_base *base)
{
	if (base)
	{
		base->o.pt.x = 0;
		base->o.pt.y = 0;
		base->o.pt.z = 0;
		base->i.pt.x = 1;
		base->i.pt.y = 0;
		base->i.pt.z = 0;
		base->j.pt.x = 0;
		base->j.pt.y = 1;
		base->j.pt.z = 0;
		base->k.pt.x = 0;
		base->k.pt.y = 0;
		base->k.pt.z = 1;
		set_base(fdf, base, O_X, O_Y);
	}
}

void			init_aux(t_fdf *fdf, int heigh, int width)
{
	int	o_x;
	int	o_y;

	if (heigh > width && width < heigh / MOD)
		width = heigh / MOD + INC_W * 2;
	if (width > heigh && heigh < width / MOD)
		heigh = width / MOD + INC_H * 2;
	fdf->heigh = heigh;
	fdf->width = width;
	if (fdf)
	{
		if (!(fdf->mlx = mlx_init()))
			check_errors(MALLOC, "init_env.c", "tmp->mlx");
		if (!(fdf->win = mlx_new_window(fdf->mlx, width, heigh, "tmp")))
			check_errors(MALLOC, "init_env.c", "fdf->win");
	}
	o_y = distance(fdf->dwn, fdf->up) / 2 < heigh / 2 ? heigh / 2 -
			distance(fdf->dwn, fdf->up) / 2 : 0;
	o_x = ((distance(fdf->lft, fdf->rgt) / 2 < width / 2) && o_y) ? width / 2 -
			distance(fdf->rgt, fdf->lft) / 2 : 0;
	move_center(fdf, &(fdf->base), o_x, o_y);
	update_tab(fdf);
}

void			aux_width(int *width, t_fdf *fdf, int a)
{
	if (*width > (MAX_WIDTH - INC_W * 2))
	{
		if (!a)
		{
			a = (int)((int)*width / (int)(OBJ_W));
			scale_base_moins(fdf, &(fdf->base), a);
			update_tab(fdf);
		}
		*width = MAX_WIDTH;
	}
	else
		*width += (INC_W * 2);
}

void			init_mlx(t_fdf *fdf)
{
	int		heigh;
	int		width;
	int		a;

	a = 0;
	heigh = distance(fdf->dwn, fdf->up);
	width = distance(fdf->rgt, fdf->lft);
	if (heigh > (MAX_HEIGH - INC_H * 2))
	{
		a = (int)((int)heigh / (int)(OBJ_H));
		scale_base_moins(fdf, &(fdf->base), a);
		update_tab(fdf);
		heigh = MAX_HEIGH;
	}
	else
		heigh += (INC_H * 2);
	aux_width(&width, fdf, a);
	init_aux(fdf, heigh, width);
}

void			init_env(t_fdf **fdf)
{
	t_fdf	*tmp;

	if (!fdf || !*fdf)
		if (!(*fdf = (t_fdf*)malloc(sizeof(t_fdf))))
			check_errors(MALLOC, "main.c", "fdf");
	tmp = *fdf;
	tmp->refresh = 1;
	tmp->tab = NULL;
	tmp->tab_h = 0;
	tmp->tab_w = 0;
	tmp->bg = NULL;
	tmp->up = -1;
	tmp->dwn = -1;
	tmp->rgt = -1;
	tmp->lft = -1;
	tmp->white = NULL;
	tmp->img = NULL;
	tmp->axe = 0;
	tmp->velx = 0;
	tmp->vely = 0;
	tmp->move = MOVE;
	if (!(tmp->lay = (t_lay*)malloc(sizeof(t_lay))))
		check_errors(MALLOC, "tmp->lay", "init_env.c");
	tmp->white = init_color(NULL, WHITE);
	init_base(tmp, &(tmp->base));
}
