/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/03 15:33:08 by imisumi          ###   ########.fr       */
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
	printf("angle1 = %f\n", data->angle1);
	printf("angle2 = %f\n", data->angle2);
	*x = (*x - *y) * cos(data->angle1);
	*y = (*x + *y) * sin(data->angle2) - z;
}

// void iso(t_fdf *data, int *x, int *y, int z)
// {
//     double angle;
//     angle = 0.8;
// 	// data->angle2 = -PI / 2;
//     printf("angle1 = %f\n", data->angle1);
//     printf("angle2 = %f\n", data->angle2);
//     *x = (*x - *y);
//     *y = (*x + *y) * sin(data->angle2) - z;
// }

void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
{
	t_draw	draw;

	draw.z = data->map[y1][x1];
	draw.z1 = data->map[y2][x2];

	// draw.z1 *= data->yshift;
	// draw.z *= data->xshift;
	x1 *= data->scale;
	y1 *= data->scale;
	x2 *= data->scale;
	y2 *= data->scale;

	iso(data, &x1, &y1, draw.z);
	iso(data, &x2, &y2, draw.z1);
	x1 += data->xshift;
	y1 += data->yshift;
	x2 += data->xshift;
	y2 += data->yshift;
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
				drawline(data, x, y, (x + 1), y);
			if (y < data->height - 1)
				drawline(data, x, y, x, (y + 1));
			x++;
		}
		y++;
	}
}
