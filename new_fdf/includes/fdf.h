/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:33:50 by bmbarga           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/14 13:37:14 by bmbarga          ###   ########.fr       */
=======
/*   Updated: 2015/01/14 08:49:07 by bmbarga          ###   ########.fr       */
>>>>>>> 9427e21b30509ca676c08fc912428744deae0b1b
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

# define HEIGH 768 * 2
# define WIDTH 1024 * 2

# define ESCAPE 65307


/*
** definition des vecteurs de bases (o, i, j, k)
*/

# define UNIT 30

# define O_X WIDTH / UNIT 
# define O_Y HEIGH / 2

# define I_X O_X + UNIT + 20
# define I_Y O_Y

# define J_X O_X
# define J_Y O_Y - 2

# define K_X O_X + 10 
# define K_Y O_Y + UNIT - 3

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
# define	COL			0xFF0000

struct				s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};


struct				s_lay
{
	void		*img;
	int			bpp;
	int			line;
	int			endian;
	int		depht;
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
	t_color		*white;
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
** draw.c
*/

void		draw_fdf(t_fdf *fdf);
void		pixel_put_img(char *image, int x, int y, t_color *col, t_lay lay, t_fdf *fdf);

/*
** color.c
*/

void		set_color(t_color *col);
t_uint		RGB_to_color(unsigned int r, unsigned int g, unsigned int b);
void		low_light(t_color *color, unsigned int inc, int sign);
void		print_color(t_color *color);
t_color		*init_color(t_color	*color, unsigned int col);

/*
** draw_line.c
*/

void	draw_line(t_fdf *fdf, t_pos A, t_pos B, t_color	*color, char *img, t_lay lay);
#endif
