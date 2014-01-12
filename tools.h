/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 02:27:57 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/12 19:01:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <mlx.h>
# include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_rect
{
	int				high;
	int				width;
}					t_rect;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

void	ft_draw_line(void *mlx, void *win, t_pos A, t_pos B);
void	struct_init(t_pos *pos, t_rect *rect);
void	pos_init(t_pos *pos, int x, int y);
void	ft_draw_line_2(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_1(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_3(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_5(void *mlx, void *win, t_pos A, t_pos B);
int		draw(void *mlx, void *win, t_rect rect, t_pos pos);

#endif
