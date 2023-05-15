/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 16:49:47 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, uint32_t color)
{
	if (x >=0 && x < WIDTH && y >=0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

void draw_line(t_fdf *data, t_line line)
{
	t_draw	draw;
	int		i;
	int		j;
	int		diff[3];
	t_rgb	p[3];
	int32_t	color;

	draw.delta_x = abs(line.x2 - line.x1);
	draw.delta_y = abs(line.y2 - line.y1);
	draw.sign_x = (line.x1 < line.x2) ? 1 : -1;
	draw.sign_y = (line.y1 < line.y2) ? 1 : -1;
	draw.err = draw.delta_x - draw.delta_y;
	while (true)
	{
		ft_mlx_put_pixel(data, line.x1, line.y1, 0xffffff);
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.delta_y)
		{
			draw.err -= draw.delta_y;
			line.x1 += draw.sign_x;
		}
		if (draw.e2 < draw.delta_x)
		{
			draw.err += draw.delta_x;
			line.y1 += draw.sign_y;
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

void	draw_rect_2(t_fdf *data, t_rect rect)
{
	int	i;
	int	j;
	int cx;
	int cy;

	i = 0;
	while (i < rect.width)
	{
		int j = 0;
		while (j < rect.height)
		{
			cx = rect.x + i;
			cy = rect.y + j;
			ft_mlx_put_pixel(data, cx, cy, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_rect_outline(t_fdf *data, t_rect rect, int thickness, uint32_t color)
{
	int	i;
	int	j;
	int cx;
	int cy;

	i = 0;
	while (i < rect.width)
	{
		int j = 0;
		while (j < rect.height)
		{
			cx = rect.x + i;
			cy = rect.y + j;
			if (cx < rect.x + thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cx >= rect.x + rect.width - thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cy < rect.y + thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cy >= rect.y + rect.height - thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			j++;
		}
		i++;
	}
}
