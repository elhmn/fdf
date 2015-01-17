/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:50:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/17 03:48:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"

void	get_limits(t_coord *e, t_fdf *fdf)
{
	if (e->pos.x < fdf->lft || !fdf->i)
	{
		fdf->lft = e->pos.x;
		fdf->i = 1;
	}
	if (e->pos.x > fdf->rgt || !fdf->j)
	{
		fdf->rgt = e->pos.x;
		fdf->j = 1;
	}
	if (e->pos.y > fdf->dwn || !fdf->k)
	{
		fdf->dwn = e->pos.y;
		fdf->k = 1;
	}
	if (e->pos.y < fdf->up || !fdf->l)
	{
		fdf->up = e->pos.y;
		fdf->l = 1;
	}
}

static void	fill_coord(t_fdf *fdf, char *nbr, int i, int j)
{
	int		alph;
	t_coord *e;

	e = fdf->tab[i] + j;
	e->pt.x = j;
	e->pt.y = ft_atoi(nbr);
	e->pt.z = i;
	e->end = 1;
	alph = 1 - e->pt.x - e->pt.y - e->pt.z;
	e->pos.x = e->pt.x * fdf->base.i.pos.x + e->pt.y * fdf->base.j.pos.x
		+ e->pt.z * fdf->base.k.pos.x + fdf->base.o.pos.x * alph;
	e->pos.y = e->pt.x * fdf->base.i.pos.y + e->pt.y * fdf->base.j.pos.y
		+ e->pt.z * fdf->base.k.pos.y + fdf->base.o.pos.y * alph;
	get_limits(e, fdf);
}

static int	line_size(char **map)
{
	int		len;

	len = 0;
	if (map)
	{
		while (*(map + len))
			len++;	
	}
	return (len);
}

void		set_tab(char ***map, t_fdf *fdf)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	if (fdf)
	{
		if (!fdf->tab)
		{
			if (!(fdf->tab = (t_coord**)malloc(sizeof(t_coord*) * (fdf->tab_h))))
				check_errors(MALLOC, "fdf->tab", "set_tab.c");
		}
		while (*(map + ++i))
		{
			if ((len = line_size(*(map + i))) > fdf->tab_w)
				fdf->tab_w = len;
			*(fdf->tab + i) = (t_coord*)malloc(sizeof(t_coord) * (len + 1));
			if (!(fdf->tab + i))
				check_errors(MALLOC, "fdf->tab + i", "set_tab.c");
			j = -1;
			while (*(*(map + i) + ++j))
				fill_coord(fdf, map[i][j],i, j);

			fdf->tab[i][j].end = 0;
		}
	}
}
