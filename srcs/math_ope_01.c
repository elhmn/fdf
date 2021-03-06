/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ope_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:16:41 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/19 19:24:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "debug.h"

void			scale_base_moins(t_fdf *fdf, t_base *base, int k)
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
	base->i.pos.x /= !i.x ? 1 : i.x;
	base->i.pos.y /= !i.y ? 1 : i.y;
	base->j.pos.x /= !j.x ? 1 : j.x;
	base->j.pos.y /= !j.y ? 1 : j.y;
	base->k.pos.x /= !l.x ? 1 : l.x;
	base->k.pos.y /= !l.y ? 1 : l.y;
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
}

static void		scale_pt_plus(t_fdf *fdf, t_pos *pos, int k)
{
	t_pos	i;

	i.x = k >= pos->x ? pos->x : k;
	i.y = k >= pos->y ? pos->y : k;
	pos->x *= (!i.x) ? 1 : i.x;
	pos->y *= (!i.y) ? 1 : i.y;
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
}

void			scale_plus(t_fdf *fdf, int k)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->tab_h)
	{
		j = -1;
		while (fdf->tab[i][++j].end)
			scale_pt_plus(fdf, &(fdf->tab[i][j].pos), k);
	}
}

static void		scale_pt_moins(t_fdf *fdf, t_pos *pos, int k)
{
	t_pos	i;

	i.x = (pos->x / k >= pos->x) ? pos->x : pos->x / k;
	i.y = (pos->y / k >= pos->y) ? pos->y : pos->y / k;
	pos->x = i.x;
	pos->y = i.y;
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
}

void			scale_moins(t_fdf *fdf, int k)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->tab_h)
	{
		j = -1;
		while (fdf->tab[i][++j].end)
			scale_pt_moins(fdf, &(fdf->tab[i][j].pos), k);
	}
}
