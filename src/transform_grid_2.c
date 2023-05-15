/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_grid_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 14:04:55 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	point_to_line_y1(t_fdf **d, int x, int y)
{
	t_fdf	*data;
	t_line	line;

	data = *d;
	line.x1 = data->projected_points[y][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y1 = data->projected_points[y][x].y + (HEIGHT / 2);
	line.x2 = data->projected_points[y + 1][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y2 = data->projected_points[y + 1][x].y + (HEIGHT / 2);
	drawline(data, line, data->map_colors[y][x], data->map_colors[y + 1][x]);
}

void	point_to_line_x1(t_fdf **d, int x, int y)
{
	t_fdf	*data;
	t_line	line;

	data = *d;
	line.x1 = data->projected_points[y][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y1 = data->projected_points[y][x].y + (HEIGHT / 2);
	line.x2 = data->projected_points[y][x + 1].x + (WIDTH / 2) + data->menu.width / 2;
	line.y2 = data->projected_points[y][x + 1].y + (HEIGHT / 2);
	drawline(data, line, data->map_colors[y][x], data->map_colors[y][x + 1]);
}

void	transform_3(t_fdf **d)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = *d;
	t_line	line;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				point_to_line_x1(&data, x, y);
			if (y < data->height - 1)
				point_to_line_y1(&data, x, y);
			x++;
		}
		y++;
	}
}
