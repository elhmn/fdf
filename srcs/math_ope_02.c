/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ope_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 21:55:28 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 22:15:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_base(t_fdf *fdf, t_base *base, int o_x, int o_y)
{
	base->o.pos.x = o_x;
	base->o.pos.y = o_y;
	base->i.pos.x = o_x + UNIT;
	base->i.pos.y = o_y;
	base->j.pos.x = o_x;
	base->j.pos.y = o_y - UNIT / 2;
	base->k.pos.x = o_x + 10;
	base->k.pos.y = o_y + UNIT - UNIT / 4;
	fdf->i = 0;
	fdf->j = 0;
	fdf->k = 0;
	fdf->l = 0;
}

int				distance(int a, int b)
{
	if (a <= 0 && b >= 0)
		return (-a + b);
	if (a >= 0 && b <= 0)
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
