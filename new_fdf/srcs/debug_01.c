/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:28:40 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/12 11:40:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
