/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 20:05:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "X.h"
# include "libft.h"
# include "get_next_line.h"

# define ABS(x) (x < 0) ? -x : x

# define FT

# ifdef FT

#  define MAX_HEIGH 1080
#  define MAX_WIDTH 1920

# endif

# ifdef HOME

#  define MAX_HEIGH 2160
#  define MAX_WIDTH 3840

# endif

# define MOVE	1
# define MOVEA	-1
# define INC_H	200
# define INC_W	200
# define MOD	2

# define OBJ_H MAX_HEIGH - (INC_H * 2)
# define OBJ_W MAX_WIDTH - (INC_W * 2)

# define K_ESCAPE 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_RIGHT 65363
# define K_LEFT 65361
# define K_ENTER 65293
# define K_PLUS 65451
# define K_MOINS 65453

# define UNIT 2000

# define O_X 0
# define O_Y 0

# define X 1
# define Y 2
# define Z -1

/*
** key_state
*/

# define PRESSED 1
# define RELEASED 0

typedef struct s_fdf	t_fdf;
typedef unsigned int	t_uint;
typedef struct s_pt		t_pt;
typedef struct s_pos	t_pos;
typedef struct s_base	t_base;
typedef struct s_coord	t_coord;
typedef struct s_lay	t_lay;
typedef struct s_color	t_color;
typedef struct s_draw	t_draw;

/*
** draw.c data
*/

# define MASK_R		0xFF0000
# define MASK_G		0x00FF00
# define MASK_B		0x0000FF

# define WHITE		0xFFFFFF

enum				e_col
{
	NEGUP = 0xAD7800,
	NEGMIUP = 0xC44C0A,
	NEGDWN = 0xBA6008,
	MIDWN = 0xA532E8,
	MIUP = 0xED43FF,
	DWN = 0x7F37FF,
	UP = 0xE832AC,
	UPPER = 0xFF3759
};

struct					s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

struct					s_draw
{
	int		ex;
	int		ey;
	int		incx;
	int		incy;
	int		dx;
	int		dy;
	t_color	*color;
};

struct					s_lay
{
	void		*img;
	int			bpp;
	int			line;
	int			endian;
	int			depht;
};

/*
** s_pt definit coordonnee dans l'espace 3D
*/

struct					s_pt
{
	int			x;
	int			y;
	int			z;
};

/*
** s_pos definit coord dans l'espace 2D
*/

struct					s_pos
{
	int			x;
	int			y;
};

/*
** s_coord combine coord dans les espaces 2D et 3D
*/

struct					s_coord
{
	t_pt		pt;
	t_pos		pos;
	int			end;
};

/*
** s_base definit les coords du repere 3D
*/

struct					s_base
{
	t_coord		o;
	t_coord		i;
	t_coord		j;
	t_coord		k;
};

/*
** tab_w est la longeur de la ligne la plus longue
** lft est le pt le plus a gauche
** rgt est le pt le plus a droite
** up est le pt le plus en haut
** dwn est le pt le plus en bas
*/

struct					s_fdf
{
	void		*mlx;
	void		*win;
	void		*bg;
	char		*img;
	t_lay		*lay;
	int			refresh;
	t_base		base;
	t_coord		**tab;
	int			lft;
	int			rgt;
	int			up;
	int			dwn;
	int			tab_h;
	int			tab_w;
	t_color		*white;
	int			key_state;
	int			heigh;
	int			width;
	int			unit;
	int			i;
	int			j;
	int			k;
	int			l;
	int			axe;
	int			velx;
	int			vely;
	int			move;
};

/*
** init_env.c
*/

void					init_env(t_fdf **fdf);
void					init_mlx(t_fdf *fdf);
int						distance(int a, int b);
void					set_base(t_fdf *fdf, t_base *base, int o_x, int o_y);

/*
** destroy_env.c
*/

void					destroy_env(t_fdf *fdf);

/*
** event_handle.c
*/

int						keyrelease_hook(int key, void *param);
int						keypress_hook(int key, void *param);
int						loop_hook(void *param);
int						expose_hook(void *param);

/*
** get_map.c
*/

void					get_data(t_fdf *fdf, char *path);

/*
** set_tab.c
*/

void					set_tab(char ***map, t_fdf *fdf);
void					get_limits(t_coord *e, t_fdf *fdf);

/*
** update_tab.c
*/

void					update_tab(t_fdf *fdf);
void					update_pt(t_fdf *fdf);
void					update_coord(t_fdf *fdf, t_coord *e);
void					fill_pt(t_fdf *fdf, t_coord *e);

/*
** draw.c
*/

int						altitude(int alt);
void					draw_fdf(t_fdf *fdf);
void					pixel_put_img(t_fdf *fdf, int x, int y, t_color *col);

/*
** color.c
*/

void					set_color(t_color *col);
t_uint					rgb_to_color(t_uint r, t_uint g, t_uint b);
void					low_light(t_color *color, unsigned int inc, int sign);
void					print_color(t_color *color);
t_color					*init_color(t_color	*color, unsigned int col);

/*
** draw_line.c
*/

void					draw_line(t_fdf *fdf, t_pos a, t_pos b, t_color	*color);

/*
** tools.c
*/

void		choose_color2(t_fdf *fdf, t_coord **tab, int i, int j);
void		choose_color1(t_fdf *fdf, t_coord **tab, int i, int j);

/*
** math_ope_01.c
*/

void					scale_plus(t_fdf *fdf, int k);
void					scale_moins(t_fdf *fdf, int k);
void					move_axis(t_base *base, int axis, int k);
void					scale_base_moins(t_fdf *fdf, t_base *base, int k);
void					scale_base_plus(t_fdf *fdf, t_base *base, int k);
void					move_center(t_fdf *fdf, t_base *base, int o_x, int o_y);
#endif
