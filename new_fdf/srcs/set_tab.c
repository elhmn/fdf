/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:50:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/13 13:26:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"

static int	line_size(char **map)
{
	int		len;

	len = 0;
	if (map)
	{
		while (*(map + len))
			len++;	
	}
	return (len);
}

void		set_tab(char ***map, t_fdf *fdf)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	if (fdf)
	{
		if (!fdf->tab)
		{
			if (!(fdf->tab = (t_coord**)malloc(sizeof(t_coord*) * (fdf->tab_h))))
				check_errors(MALLOC, "fdf->tab", "set_tab.c");
		}
		// change map en coord
		while (*(map + ++i))
		{
			len = line_size(*(map + i));
			*(fdf->tab + i) = (t_coord*)malloc(sizeof(t_coord) * (len + 1));
			if (!(fdf->tab + i))
				check_errors(MALLOC, "fdf->tab + i", "set_tab.c");
			fdf->tab[i][len].end = -1;
			j = -1;
			while (*(*(map + i) + ++j))
			{
				fdf->tab[i][j].pt.x = j;
				fdf->tab[i][j].pt.y = i;
				fdf->tab[i][j].pt.z = ft_atoi(map[i][j]);
				fdf->tab[i][j].end = 1;
				//get 2D pos
//				fdf->tab[i][j].pos.x = ;
//				fdf->tab[i][j].pos.y = ;
			}
			fdf->tab[i][j].end = 0;
		}
	}
}
