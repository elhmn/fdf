/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/11 21:40:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "X.h"
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define HEIGH 768
# define WIDTH 1024

# define ESCAPE 65307

typedef struct s_fdf	t_fdf;
typedef unsigned int	t_uint;

struct			s_fdf
{
	void	*mlx;
	void	*win;
	void	*bg;
	int		refresh;
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

#endif
