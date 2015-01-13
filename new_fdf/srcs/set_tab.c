/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:50:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/13 10:01:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_tab(char ***map, t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (fdf)
	{
		if (!fdf->tab)
		{
			if (!(fdf->tab = (t_coord**)malloc(sizeof(coord*) * (fdf->tab_h))))
				check_errors(MALLOC, "fdf->tab", "set_tab.c");
		}
		// change map en coord
		while ()
		{
			
		}
	}
}
