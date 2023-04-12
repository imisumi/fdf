/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/12 13:47:04 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>
#define PI 3.14159265

void	iso(t_fdf *data, int *x, int *y, int z)
{
	double	angle;
	angle = 0.8;
	// printf("angle1 = %f\n", data->angle1);
	// printf("angle2 = %f\n", data->angle2);
	*x = (*x - *y) * cos(data->angle1);
	*y = (*x + *y) * sin(data->angle2) - z;
}

void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
{
	t_draw	draw;

	draw.dx = abs(x2 - x1);
	draw.dy = abs(y2 - y1);
	draw.sx = (x1 < x2) ? 1 : -1;
	draw.sy = (y1 < y2) ? 1 : -1;
	draw.err = draw.dx - draw.dy;
	while (1)
	{
		mlx_put_pixel(data->image, x1, y1, 0xffffff);
		if (x1 == x2 && y1 == y2)
			break ;
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.dy)
		{
			draw.err -= draw.dy;
			x1 += draw.sx;
		}
		if (draw.e2 < draw.dx)
		{
			draw.err += draw.dx;
			y1 += draw.sy;
		}
	}
}

// void	draw_grid(t_fdf *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			if (x < data->width - 1)
// 				drawline(data, x, y, (x + 1), y);
// 			if (y < data->height - 1)
// 				drawline(data, x, y, x, (y + 1));
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_rect(t_fdf *data, int x, int y, int width, int height, uint32_t color)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			int	cx = x + i;
			int	cy = y + j;
			// printf("%d, %d\n", cy, cx);
			mlx_put_pixel(data->image, cx, cy, color);
			// mlx_put_pixel(data->image, data->grid[y][x].x, data->grid[y][x].y, 0xffffff);
			// color_buffer[(WIDTH * cy) + cx] = color;
		}
}

void	draw_point_grid(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_rect(data, data->projected_point[y][x].x, data->projected_point[y][x].y, 2, 2, 0xffffff);
			draw_rect(data, data->grid[y][x].x, data->grid[y][x].y, 2, 2, 0xffffff);
			// mlx_put_pixel(data->image, data->grid[y][x].x, data->grid[y][x].y, 0xffffff);
			printf("%f, %f\n", data->grid[y][x].x, data->grid[y][x].y);
			printf("%f, %f\n", data->projected_point[y][x].y, data->projected_point[y][x].y);
			x++;
		}
		y++;
	}
}

void	draw_grid(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				drawline(data, data->grid[y][x].x, data->grid[y][x].y, data->grid[y][x + 1].x, data->grid[y][x].y);
			}
			// return ;
			if (y < data->height - 1)
			{
				drawline(data, data->grid[y][x].x, data->grid[y][x].y, data->grid[y][x].x, data->grid[y + 1][x].y);
			}
			// return ;
			x++;
		}
		y++;
	}
}
