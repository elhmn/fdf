/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:33:40 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 19:31:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

t_color	*init_color(t_color *color, t_uint col)
{
	if (!color)
		if (!(color = (t_color*)malloc(sizeof(t_color))))
			check_errors(MALLOC, "color", "color.c");
	color->color = col;
	color->r = (col & MASK_R) >> (8 * 2);
	color->g = (col & MASK_G) >> 8;
	color->b = (col & MASK_B);
	color->alpha = 0;
	return (color);
}

void	set_color(t_color *col)
{
	if (col)
	{
		col->r = (col->color & MASK_R) >> (8 * 2);
		col->g = (col->color & MASK_G) >> 8;
		col->b = (col->color & MASK_B);
		col->alpha = 0;
	}
}

t_uint	rgb_to_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}

void	print_color(t_color *color)
{
	if (color)
	{
		printf("color->col = [%d]\n", color->color);
		printf("color->r = [%d]\n", color->r);
		printf("color->g = [%d]\n", color->g);
		printf("color->b = [%d]\n", color->b);
		printf("color->a = [%d]\n", color->alpha);
	}
}
