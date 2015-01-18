/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:42 by elhmn             #+#    #+#             */
/*   Updated: 2015/01/18 19:37:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		choose_color1(t_fdf *fdf, t_coord **tab, int i, int j)
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

void		choose_color2(t_fdf *fdf, t_coord **tab, int i, int j)
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
