/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:42 by elhmn             #+#    #+#             */
/*   Updated: 2015/01/18 21:35:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			move_axis(t_base *base, int axis, int k)
{
	if (axis == Y)
	{
		base->j.pos.x += k;
		base->j.pos.y += k;
		base->k.pos.x += k;
		base->k.pos.y += k;
		base->i.pos.x += k;
		base->i.pos.y += k;
	}
}

void			choose_color1(t_fdf *fdf, t_coord **tab, int i, int j)
{
	int		alt1;
	int		alt2;

	alt1 = altitude(tab[i + 1][j].pt.y);
	alt2 = altitude(tab[i][j].pt.y);
	if (alt1 == DWN || alt2 == DWN)
		fdf->white = init_color(NULL, DWN);
	else if (alt1 == MIDWN || alt2 == MIDWN)
		fdf->white = init_color(NULL, MIDWN);
	else if (alt1 == MIUP || alt2 == MIUP)
		fdf->white = init_color(NULL, MIUP);
	else if (alt1 == UP || alt2 == UP)
		fdf->white = init_color(NULL, UP);
	else if (alt1 == UPPER || alt2 == UPPER)
		fdf->white = init_color(NULL, UPPER);
	else if (alt1 == NEGDWN || alt2 == NEGDWN)
		fdf->white = init_color(NULL, NEGDWN);
	else if (alt1 == NEGMIUP || alt2 == NEGMIUP)
		fdf->white = init_color(NULL, NEGMIUP);
	else if (alt1 == NEGUP || alt2 == NEGUP)
		fdf->white = init_color(NULL, NEGUP);
}

void			choose_color2(t_fdf *fdf, t_coord **tab, int i, int j)
{
	int		alt1;
	int		alt2;

	alt1 = altitude(tab[i][j].pt.y);
	alt2 = altitude(tab[i][j + 1].pt.y);
	if (alt1 == DWN || alt2 == DWN)
		fdf->white = init_color(NULL, DWN);
	else if (alt1 == MIDWN || alt2 == MIDWN)
		fdf->white = init_color(NULL, MIDWN);
	else if (alt1 == MIUP || alt2 == MIUP)
		fdf->white = init_color(NULL, MIUP);
	else if (alt1 == UP || alt2 == UP)
		fdf->white = init_color(NULL, UP);
	else if (alt1 == UPPER || alt2 == UPPER)
		fdf->white = init_color(NULL, UPPER);
	else if (alt1 == NEGDWN || alt2 == NEGDWN)
		fdf->white = init_color(NULL, NEGDWN);
	else if (alt1 == NEGMIUP || alt2 == NEGMIUP)
		fdf->white = init_color(NULL, NEGMIUP);
	else if (alt1 == NEGUP || alt2 == NEGUP)
		fdf->white = init_color(NULL, NEGUP);
}

void			scale_base_plus(t_fdf *fdf, t_base *base, int k)
{
	t_pos	i;
	t_pos	j;
	t_pos	l;

	i.x = k >= base->i.pos.x ? base->i.pos.x : k;
	i.y = k >= base->i.pos.y ? base->i.pos.y : k;
	j.x = k >= base->j.pos.x ? base->j.pos.x : k;
	j.y = k >= base->j.pos.y ? base->j.pos.y : k;
	l.x = k >= base->k.pos.x ? base->k.pos.x : k;
	l.y = k >= base->k.pos.y ? base->k.pos.y : k;
	base->i.pos.x *= !i.x ? 1 : i.x;
	base->i.pos.y *= !i.y ? 1 : i.y;
	base->j.pos.x *= !j.x ? 1 : j.x;
	base->j.pos.y *= !j.y ? 1 : j.y;
	base->k.pos.x *= !l.x ? 1 : l.x;
	base->k.pos.y *= !l.y ? 1 : l.y;
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
}

void			move_center(t_fdf *fdf, t_base *base, int o_x, int o_y)
{
	int		tmpx;
	int		tmpy;

	fdf = fdf;
	tmpx = base->o.pos.x;
	tmpy = base->o.pos.y;
	base->o.pos.x = o_x;
	base->o.pos.y = o_y;
	base->i.pos.x = o_x + distance(tmpx, base->i.pos.x);
	base->i.pos.y = o_y + distance(tmpy, base->i.pos.y);
	base->j.pos.x = o_x + distance(tmpx, base->j.pos.x);
	base->j.pos.y = o_y - distance(tmpy, base->j.pos.y);
	base->k.pos.x = o_x + distance(tmpx, base->k.pos.x);
	base->k.pos.y = o_y + distance(tmpy, base->k.pos.y);
}
