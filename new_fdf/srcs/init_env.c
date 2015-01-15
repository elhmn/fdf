/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 09:30:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

void			set_base(t_fdf *fdf, t_base *base, int o_x, int o_y)
{
	fdf = fdf;
	base->o.pos.x = o_x;
	base->o.pos.y = o_y;
	base->i.pos.x = o_x + UNIT + 20;
	base->i.pos.y = o_y;
	base->j.pos.x = o_x;
	base->j.pos.y = o_y - 2;
	base->k.pos.x = o_x + 10;
	base->k.pos.y = o_y + UNIT - 3;
}

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

void		init_mlx(t_fdf *fdf)
{
	int		heigh;
	int		width;
	int		o_x;
	int		o_y;
	
	heigh = fdf->dwn - fdf->up + INC_H * 2;
	width = fdf->rgt - fdf->lft + INC_W * 2;
	if (heigh > MAX_HEIGH)
		heigh = MAX_HEIGH;
	if (width > MAX_WIDTH)
		width = MAX_WIDTH;
	if (heigh > width && width < heigh / MOD)
		width = heigh / MOD;
	if (width > heigh && heigh < width / MOD)
			heigh = width / MOD;
	fdf->heigh = heigh;
	fdf->width = width;
	if (fdf)
	{
		if (!(fdf->mlx = mlx_init()))
				check_errors(MALLOC, "init_env.c", "tmp->mlx");
		if (!(fdf->win = mlx_new_window(fdf->mlx, width, heigh, "tmp")))
			check_errors(MALLOC, "init_env.c", "fdf->win");
	}
	o_x = width / 2 - (fdf->rgt - fdf->lft) / 2;
	o_y = heigh / 2 - (fdf->dwn - fdf->up) / 2;
	set_base(fdf, &(fdf->base), o_x, o_y);
}


void	init_env(t_fdf **fdf)
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
	if (!(tmp->lay = (t_lay*)malloc(sizeof(t_lay))))
			check_errors(MALLOC, "tmp->lay", "init_env.c");
	tmp->white = init_color(NULL, WHITE);
	print_color(tmp->white); /************/
	init_base(tmp, &(tmp->base));
}
