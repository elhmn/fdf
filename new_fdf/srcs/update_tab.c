/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 08:12:36 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/15 13:57:58 by bmbarga          ###   ########.fr       */
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
			update_coord(fdf, tab[i] + j);
	}
}
