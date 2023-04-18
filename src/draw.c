/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/18 21:47:28 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, uint32_t color)
{
	if (x >=0 && x < WIDTH && y >=0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
{
	t_draw	draw;

	draw.delta_x = abs(x2 - x1);
	draw.delta_y = abs(y2 - y1);
	draw.sign_x = (x1 < x2) ? 1 : -1;
	draw.sign_y = (y1 < y2) ? 1 : -1;
	draw.err = draw.delta_x - draw.delta_y;
	while (1)
	{
		ft_mlx_put_pixel(data, x1, y1, 0xffffff);
		if (x1 == x2 && y1 == y2)
			break ;
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.delta_y)
		{
			draw.err -= draw.delta_y;
			x1 += draw.sign_x;
		}
		if (draw.e2 < draw.delta_x)
		{
			draw.err += draw.delta_x;
			y1 += draw.sign_y;
		}
	}
}

void	draw_rect(t_fdf *data, int x, int y, int width, int height, uint32_t color)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			int	cx = x + i;
			int	cy = y + j;
			// printf("%d, %d\n", cy, cx);
			// mlx_put_pixel(data->image, cx, cy, color);
			ft_mlx_put_pixel(data, cx, cy, color);

			
			// mlx_put_pixel(data->image, data->grid[y][x].x, data->grid[y][x].y, 0xffffff);
			// color_buffer[(WIDTH * cy) + cx] = color;
		}
}

void	draw_grid(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			drawline(data, x, y, x, WIDTH);
			x += 20;
		}
		drawline(data, 0, y, WIDTH, y);
		y += 20;
	}
}
