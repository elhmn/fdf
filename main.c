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

#include "tools.h"

int		draw(void *mlx, void *win, t_rect rect, t_pos pos)
{
	int		i;
	int		j;

	i = 0;
	while(i < rect.high)
	{
		j = 0;
		while (j < rect.width)
		{
			mlx_pixel_put(mlx, win, pos.x + j, pos.y + i, 0x00FF00);
			usleep(500);
			j++;
		}
		i++;
	}
	return (0);
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

	t_rect			prect;

	prect.high = 5;
	prect.width = 5;
	
	//i = 0;
	struct_init(&rect_pos, &rect);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "42");
	pos_init(&A, 100, 1);
	pos_init(&B, 0, 300);
	draw(mlx, win, prect, A);
	draw(mlx, win, prect, B);
	ft_draw_line_3(mlx, win, A, B);
//	pos_init(&A, 10, 400);
//	pos_init(&B, 200, 0);
//	ft_draw_line(mlx, win, A, B);
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
