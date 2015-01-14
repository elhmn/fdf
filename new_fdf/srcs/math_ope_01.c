/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ope_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:16:41 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/13 18:29:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	det_coord(char **map, int x, int z, t_mark mark)
{
	t_pos   A;
	int		k;
	int		y;

	y = ft_atoi(map[x]);
	k = 1 - x - y - z;
	A.x = x * mark.i.x + y * mark.j.x + z * mark.k.x + mark.o.x * k;
	A.y = x * mark.i.y + y * mark.j.y + z * mark.k.y + mark.o.y * k;
	return (A);
}
