/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:25:58 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/11 20:45:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"

void	destroy_env(t_fdf *fdf)
{
	if (!fdf)
		check_errors(NUL, "init_env", "init_env.c");
	if (fdf->win && fdf->mlx)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
}
