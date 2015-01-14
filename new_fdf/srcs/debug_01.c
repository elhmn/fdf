/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:28:40 by bmbarga           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/13 18:20:03 by bmbarga          ###   ########.fr       */
=======
/*   Updated: 2015/01/13 13:15:53 by bmbarga          ###   ########.fr       */
>>>>>>> 4ac5663dc54ca011e8088e3f4db1868021857bf1
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "debug.h"

void		print_type(char *str, void *elem, int type)
{
	int		*nbr;
	char	*car;

	if (type == INT)
	{
		nbr = (int*)elem;
		ft_putstr(str);
		ft_putstr(" = [");
		ft_putnbr(*nbr);
		ft_putendl("]");
	}
	if (type == CHAR)
	{
		car = (char*)elem;
		ft_putstr(str);
		ft_putstr(" = [");
		ft_putstr(car);
		ft_putendl("]");
	}
}

void		print_map(char **map)
{
	if (map)
	{
		while (*map)
		{
			ft_putstr("[");
			ft_putstr(*map);
			ft_putendl("]");
			map++;
		}
	}
}

void		print_coord(t_coord **tab, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (tab[i][++j].end)
		{
			ft_putstr("tab[");
			ft_putnbr(i);
			ft_putstr("]");
			ft_putstr("[");
			ft_putnbr(j);
			ft_putstr("] = [");
			ft_putnbr(tab[i][j].pt.x);
			ft_putstr("], [");
			ft_putnbr(tab[i][j].pt.y);
			ft_putstr("], [");
			ft_putnbr(tab[i][j].pt.z);
			ft_putstr("]");
			ft_putstr(" && ");
			ft_putstr("[");
			ft_putnbr(tab[i][j].pos.x);
			ft_putstr("], [");
			ft_putnbr(tab[i][j].pos.y);
			ft_putstr("]");
			if (tab[i][j + 1].end)
				ft_putstr(" || ");
		}
		ft_putendl("");
	}
}

void		print_tab(char ***tab)
{
	int		i;
	int		j;

	i = -1;
	while (*(tab + ++i))
	{
		j = -1;
		while (*(tab[i] + ++j))
		{
			ft_putstr("[");
			ft_putstr(tab[i][j]);
			ft_putstr("]");
			if (tab[i][j + 1])
				ft_putstr(" ");
		}
		ft_putendl("");
	}
}
