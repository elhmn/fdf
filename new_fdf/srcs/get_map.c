/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 08:42:15 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/12 11:42:17 by bmbarga          ###   ########.fr       */
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
		check_errors(NUL, "s1", "get_map.c");;
	free(tmp);
}

static char	**get_map(int fd, int h, int w)
{
	char	**map;
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
		h++;
		free(line);
	}
	map = ft_strsplit(str, '\n');
	print_map(map);
	w++;
	map = map; /******* a virer ********/
	return (map);
}

void		get_data(t_fdf *fdf, char *path)
{
	char	**map;
	int		fd;
	int		h;
	int		w;

	h = 0;
	w = 0;
	fdf = fdf;
	if ((fd = open(path, O_RDONLY)) == -1)
		sys_errors("fd");
	map = get_map(fd, h, w);
	map = map; /******* a virer ********/
	if (close(fd) == -1)
		sys_errors("fd");
}
