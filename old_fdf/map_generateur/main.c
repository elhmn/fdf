/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 00:03:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/01/15 00:48:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#define HIGH 10 
#define WIDTH 10


int		fileset(int fd)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	srand(time(NULL));
	while (i < HIGH)
	{
		j = 0;
		while (j < WIDTH)
		{
			c = '0' + rand() % ('9' - '0');
			write(fd, &c, 1);
			write(fd, " ", 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	//int		ret;
	//char	c;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR)) < 0)
		{
			perror("open");
			return (0);
		}
		fileset(fd);
		/*
		 while ((ret = read(fd, &c, 1)) > 0)
		{
			printf("%c", c);
		}
		*/
		if (close(fd) < 0 ) //|| ret < 0)
		{
			perror("close");
			return (0);
		}
	}
	else
	{
		printf("No file name set");
	}
	return (0);
}
