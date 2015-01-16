/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:57:42 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/16 16:17:28 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"
#include <stdio.h>



void			set_base(t_fdf *fdf, t_base *base, int o_x, int o_y)
{
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

int				distance(int a, int b)
{
	if (a <= 0 &&  b >= 0)
		return (-a + b);
	if (a >= 0 &&  b <= 0)
		return (a + -b);
	if (a <= 0 && b <= 0 && a <= b)
		return (-a - -b);
	if (a <= 0 && b <= 0 && b <= a)
		return (-b - -a);
	if (a >= 0 && b >= 0 && b <= a)
		return (a - b);
	if (a >= 0 && b >= 0 && a <= b)
		return (b - a);
	return (0);
}

void			init_mlx(t_fdf *fdf)
{
	int		heigh;
	int		width;
	int		o_x;
	int		o_y;
	int		a;
	
	print_type("fdf->lft", &(fdf->lft), INT); /**********/
	print_type("fdf->rgt", &(fdf->rgt), INT); /**********/
	print_type("fdf->up", &(fdf->up), INT); /**********/
	print_type("fdf->dwn", &(fdf->dwn), INT); /**********/
	heigh = distance(fdf->dwn, fdf->up);
	width = distance(fdf->rgt, fdf->lft);
	a = 0;
	print_type("heigh", &(heigh), INT); /**********/
	print_type("width", &(width), INT); /**********/
	if (heigh > (MAX_HEIGH - INC_H * 2))
	{
		ft_putendl("heigh > M_H - k * 2"); /**************/
		ft_putendl("before"); /********/
		print_base(&(fdf->base));
		a = (int)((int)heigh / (int)(OBJ_H));
		scale_base_moins(fdf, &(fdf->base), a);
		ft_putendl("after");/***********/
		print_base(&(fdf->base)); /**********/
		update_tab(fdf);
		heigh = MAX_HEIGH;
//		print_coord(fdf->tab, fdf->tab_h);
	//	}
	}
	else
		heigh += (INC_H * 2);
	if (width > (MAX_WIDTH - INC_W * 2))
	{
		if (!a)
		{
			ft_putendl("width > M_W - k * 2"); /**************/
			ft_putendl("before");/********/
			print_base(&(fdf->base));
			a = (int)((int)width / (int)(OBJ_W));
			scale_base_moins(fdf, &(fdf->base), a);
			ft_putendl("after");/***********/
			print_base(&(fdf->base)); /**********/
			update_tab(fdf);
		}
		width = MAX_WIDTH;
//	}
	}
	else
		width += (INC_W * 2);
	/********** ATTENTION BUG POSSIBLE ******/
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
	print_type("fdf->lft", &(fdf->lft), INT); /**********/
	print_type("fdf->rgt", &(fdf->rgt), INT); /**********/
	print_type("fdf->up", &(fdf->up), INT); /**********/
	print_type("fdf->dwn", &(fdf->dwn), INT); /**********/
	o_y = distance(fdf->dwn, fdf->up) / 2 < heigh / 2 ? heigh / 2 - distance(fdf->dwn, fdf->up) / 2 : 0;
	o_x = ((distance(fdf->lft, fdf->rgt) / 2 < width / 2) && o_y) ? width / 2 - distance(fdf->rgt, fdf->lft) / 2 : 0;
	move_center(fdf, &(fdf->base), o_x, o_y);
	print_base(&(fdf->base));
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
