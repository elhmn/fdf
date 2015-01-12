/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 09:43:15 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/12 09:52:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	fd = 0;
	i = 1;
	if (ac == 2)
		if (!(fd = open(av[1], O_RDONLY)) == -1)
				perror("fd");
	if (ac > 2)
		return (-1);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf("Error while reading file\n");
			break;
		}
		printf("%d --> [%s]\n", i, line);
		i++;
		free(line);
	}
	return (0);
}
