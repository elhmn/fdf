/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:12:36 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/17 03:50:56 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	update_coord(t_fdf *fdf, t_coord *e)
{
	int		alph;
	
	alph = 1 - e->pt.x - e->pt.y - e->pt.z;
	e->pos.x = e->pt.x * fdf->base.i.pos.x + e->pt.y * fdf->base.j.pos.x
		+ e->pt.z * fdf->base.k.pos.x + fdf->base.o.pos.x * alph;
	e->pos.y = e->pt.x * fdf->base.i.pos.y + e->pt.y * fdf->base.j.pos.y
		+ e->pt.z * fdf->base.k.pos.y + fdf->base.o.pos.y * alph;

}

void		fill_pt(t_fdf *fdf, t_coord *e)
{

	if (fdf->move == MOVE)
	{
		if (e->pt.y)
		{
			e->pt.y += fdf->vely;
			if (!e->pt.y && fdf->vely > 0)
				e->pt.y = 1;
			if (!e->pt.y && fdf->vely < 0)
					e->pt.y = -1;
		}
		if (e->pt.y)
			e->pt.x += fdf->velx;
	}
	else
	{
		e->pt.x += fdf->velx;
//		e->pt.x = j;
		e->pt.z += fdf->vely;
//		e->pt.x += fdf->velx;
//		e->pt.z = i;
	}
	update_coord(fdf, e);
	get_limits(e, fdf);
}

void	update_pt(t_fdf *fdf)
{
	t_coord 	**tab;
	int			i;
	int			j;

	i = -1;
	tab = fdf->tab;
	while (++i < fdf->tab_h)
	{
		j = -1;
		while (tab[i][++j].end)
		{
			fill_pt(fdf, tab[i] + j);
			get_limits(tab[i] + j, fdf);
		}
	}
}

void	update_tab(t_fdf *fdf)
{
	t_coord 	**tab;
	int			i;
	int			j;

	i = -1;
	tab = fdf->tab;
	while (++i < fdf->tab_h)
	{
		j = -1;
		while (tab[i][++j].end)
		{
			update_coord(fdf, tab[i] + j);
			get_limits(tab[i] + j, fdf);
		}
	}
}
