/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:12:37 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/10 21:12:37 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

int		draw(void *mlx, void *win, t_rect rect, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	while(i < rect.high)
	{
		j = 0;
		while (j < rect.width)
		{
			mlx_pixel_put(mlx, win, pos.x + j, pos.y + i, 0xFFFFFF);
			usleep(500);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_draw_line(void *mlx, void *win, t_pos A, t_pos B)
{
	float		a;
	float		b;

//	if (A.x > B.x || A.y > B.y)
//		ft_draw_line(mlx, win, B, A);
//	else
//	{
		a = (float) ( (B.y - A.y) / (B.x - A.x));
		b = A.y - a * A.x;
		while (A.x <= B.x)
		{
			A.y = (int)(a * A.x + b);
			mlx_pixel_put(mlx, win, A.x++, A.y, 0xFFFFFF);
			usleep(10000);
		}
//	}
}

void	struct_init(t_pos *pos, t_rect *rect)
{
	rect->high = 50;
	rect->width = 100;
	pos->x = 200 - rect->width / 2;
	pos->y = 200 - rect->high / 2;
}

void	pos_init(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

int		main(void)
{
	//int 	i;
	void	*mlx;
	void	*win;
	t_rect	rect;
	t_pos	A;
	t_pos	B;
	t_pos	rect_pos;

	//i = 0;
	struct_init(&rect_pos, &rect);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "42");
	pos_init(&A, 0, 0);
	pos_init(&B, 100, 400);
	ft_draw_line(mlx, win, A, B);
	pos_init(&A, 10, 200);
	pos_init(&B, 100, 10);
	ft_draw_line(mlx, win, A, B);
	//draw(mlx, win, rect, rect_pos);
	/*while (i < 400)
		mlx_pixel_put(mlx, win, 200, 0 + i++, 0xFF0000);
	i = 0;
	while (i < 400)
		mlx_pixel_put(mlx, win, 0 + i++, 200, 0xFF0000);
	*/
	sleep(50);
	mlx_destroy_window(mlx, win);
	return (0);
}
