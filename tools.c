/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:42 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/11 18:54:42 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
