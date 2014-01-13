/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 02:27:57 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/13 03:07:13 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# define UNIT 25

typedef struct		s_rect
{
	int				high;
	int				width;
}					t_rect;

enum				e_color
{
	BLUE = 0x0000FF,
	RED = 0xFF0000,
	YELLOW = 0xFFFF00,
	GREEN = 0x00FF00,
	WHITE = 0xFFFFFF
};


typedef struct		t_pt
{
	int				x;
	int				y;
	int				z;
}					t_pt;

/*
typedef struct		s_vect
{
	int				i;
	int				j;
	int				k;
}					t_vect;
*/

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef	struct	s_mark
{
	t_pos		o;
	t_pos		i;
	t_pos		j;
	t_pos		k;
}				t_mark;

typedef struct s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void	ft_draw_line_5(void *mlx, void *win, t_pos A, t_pos B);
void	struct_init(t_pos *pos, t_rect *rect);
void	pos_init(t_pos *pos, int x, int y);
void	ft_draw_line_2(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_1(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_3(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line_4(void *mlx, void *win, t_pos A, t_pos B);
void	ft_draw_line(t_env e, t_pos A, t_pos B, int color);
int		draw(void *mlx, void *win, t_rect rect, t_pos pos);

#endif
