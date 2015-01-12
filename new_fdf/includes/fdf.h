/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/12 17:04:48 by bmbarga          ###   ########.fr       */
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

typedef struct s_fdf	t_fdf;
typedef unsigned int	t_uint;
typedef struct s_pt		t_pt;
typedef struct s_pos	t_pos;
typedef struct s_base	t_base;
typedef struct s_coord	t_coord;

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

#endif
