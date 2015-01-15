/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 13:35:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"
#include <stdio.h>

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
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
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
	double	tmp1;
	double	tmp2;
	
	tmp1 = sqrt((pow(fdf->up, 2) - pow(fdf->dwn, 2)));
//	printf("tmp1 = [%lf]", tmp1); /*****/
	tmp2 = sqrt((pow(fdf->rgt, 2) - pow(fdf->lft, 2)));
//	printf("tmp2 = [%lf]", tmp2);/*********/
	heigh = (int)tmp1;
	width = (int)tmp2;
	print_type("heigh", &(heigh), INT); /**********/
	print_type("width", &(width), INT); /**********/
	if (heigh > (MAX_HEIGH - INC_H * 2))
	{
		ft_putendl("heigh > M_H - k * 2"); /**************/
		heigh = MAX_HEIGH;
//		et redim;
	}
	else
		heigh += (INC_H * 2);
	if (width > (MAX_WIDTH - INC_W * 2))
	{
		ft_putendl("width > M_W - k * 2"); /**************/
		width = MAX_WIDTH;
//		et redim;
	}
	else
		width += (INC_W * 2);
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
