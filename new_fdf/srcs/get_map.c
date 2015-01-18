/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 08:42:15 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 21:27:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "check_errors.h"
#include "debug.h"

static	void	secu_strjoin(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	if (!(*s1 = ft_strjoin(*s1, s2)))
		check_errors(NUL, "s1", "get_map.c");
	free(tmp);
}

static char		***build_map(char ***map, int size)
{
	char	***tab;
	char	**tmp;
	int		i;

	tmp = *map;
	i = -1;
	if (!(tab = (char***)malloc(sizeof(char**) * (size + 1))))
		check_errors(MALLOC, "tab", "get_map.c");
	while (++i < size)
	{
		tab[i] = ft_strsplit(tmp[i], ' ');
	}
	tab[size] = NULL;
	return (tab);
}

static int		map_size(char **map)
{
	int		len;

	len = 0;
	if (map)
	{
		while (*map++)
			len++;
	}
	return (len);
}

static char		***get_map(int fd, t_fdf *fdf)
{
	char	**map;
	char	***tab;
	char	*line;
	char	*str;
	int		ret;

	map = NULL;
	str = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			sys_errors("ret");
		secu_strjoin(&str, line);
		secu_strjoin(&str, "\n");
		free(line);
	}
	map = ft_strsplit(str, '\n');
	fdf->tab_h = map_size(map);
	tab = build_map(&map, fdf->tab_h);
	return (tab);
}

void			get_data(t_fdf *fdf, char *path)
{
	char	***map;
	int		fd;

	fdf = fdf;
	if ((fd = open(path, O_RDONLY)) == -1)
		sys_errors("fd");
	map = get_map(fd, fdf);
	print_tab(map);
	set_tab(map, fdf);
	if (close(fd) == -1)
		sys_errors("fd");
}
