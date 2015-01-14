/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:42 by elhmn             #+#    #+#             */
/*   Updated: 2015/01/13 17:16:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "libft.h"

/*
void	struct_init(t_pos *pos, t_rect *rect)
{
	rect->high = 50;
	rect->width = 100;
	pos->x = 200 - rect->width / 2;
	pos->y = 200 - rect->high / 2;
}

void	pos_init(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void	ft_pixel_put(t_env e, t_pos A, int couleur)
{
	mlx_pixel_put(e.mlx, e.win, A.x, A.y, couleur);
}
*/

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

/*
t_pos	2d_to_3d(int x, int y, int z)
{
	t_pos	A;
	int		k;
	
	k = 1 - x - y - z;
	A.x = x * mark.i.x + y * mark.j.x + z * mark.k.x + mark.o.x * k;
	A.y = x * mark.i.y + y * mark.j.y + z * mark.k.y + mark.o.y * k;
	return (A);
}

void	vect_prod(t_pt u, t_pt v, t_pt w)
{
	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
}*/
