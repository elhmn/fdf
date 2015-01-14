/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/13 19:35:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "X.h"
# include "libft.h"
# include "get_next_line.h"

# define HEIGH 768
# define WIDTH 1024

# define ESCAPE 65307


/*
** definition des vecteurs de bases (o, i, j, k)
*/

# define UNIT 25

# define O_X WIDTH / 2
# define O_Y HEIGH / 2

# define I_X O_X + UNIT
# define I_Y O_Y

# define J_X O_X
# define J_Y O_Y + UNIT

# define K_X O_X - UNIT
# define K_Y O_Y - UNIT

typedef struct s_fdf	t_fdf;
typedef unsigned int	t_uint;
typedef struct s_pt		t_pt;
typedef struct s_pos	t_pos;
typedef struct s_base	t_base;
typedef struct s_coord	t_coord;
typedef struct s_lay	t_lay;
typedef struct s_color	t_color;

/*
** draw.c data
*/

# define	MASK_R		0xFF0000
# define	MASK_G		0x00FF00
# define	MASK_B		0x0000FF

struct				s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};


typedef struct		s_lay
{
	void		*img;
	t_uint		bpp;
	t_uint		line;
	t_uint		endian;
	t_uint		depht;
};


/*
** s_pt definit coordonnee dans l'espace 3D
*/

struct			s_pt
{
	int			x;
	int			y;
	int			z;
};

/*
** s_pos definit coord dans l'espace 2D
*/

struct			s_pos
{
	int			x;
	int			y;
};

/*
** s_coord combine coord dans les espaces 2D et 3D
*/

struct			s_coord
{
	t_pt		pt;
	t_pos		pos;
	int			end;
};

/*
** s_base definit les coords du repere 3D
*/

struct			s_base
{
	t_coord		o;
	t_coord		i;
	t_coord		j;
	t_coord		k;
};

struct			s_fdf
{
	void		*mlx;
	void		*win;
	void		*bg;
	int			refresh;
	t_base		base;
	t_coord		**tab;
	int			tab_h;
};

/*
** init_env.c
*/

void			init_env(t_fdf **fdf);

/*
** destroy_env.c
*/

void			destroy_env(t_fdf *fdf);

/*
** event_handle.c
*/

int				keyRelease_hook(int key, void *param);
int				keyPress_hook(int key, void *param);
int				loop_hook(void *param);

/*
** get_map.c
*/

void			get_data(t_fdf *fdf, char *path);

/*
** set_tab.c
*/

void			set_tab(char ***map, t_fdf *fdf);

/*
** draw_fdf.c
*/

void		draw_fdf(t_fdf *fdf);
void		pixel_put_img(char *image, int x, int y, t_color *col, t_lay *line);

/*
** color.c
*/

void	set_color(t_color *col);
unsigned int	RGB_to_color(unsigned int r, unsigned int g, unsigned int b);
void	low_light(t_color *color, unsigned int inc, int sign);

#endif
