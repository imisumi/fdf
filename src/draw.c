/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/25 17:05:15 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, uint32_t color)
{
	if (x >=0 && x < WIDTH && y >=0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

// void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
// {
// 	t_draw	draw;

// 	draw.delta_x = abs(x2 - x1);
// 	draw.delta_y = abs(y2 - y1);
// 	draw.sign_x = (x1 < x2) ? 1 : -1;
// 	draw.sign_y = (y1 < y2) ? 1 : -1;
// 	draw.err = draw.delta_x - draw.delta_y;
// 	while (1)
// 	{
// 		ft_mlx_put_pixel(data, x1, y1, 0xffffff);
// 		if (x1 == x2 && y1 == y2)
// 			break ;
// 		draw.e2 = 2 * draw.err;
// 		if (draw.e2 > -draw.delta_y)
// 		{
// 			draw.err -= draw.delta_y;
// 			x1 += draw.sign_x;
// 		}
// 		if (draw.e2 < draw.delta_x)
// 		{
// 			draw.err += draw.delta_x;
// 			y1 += draw.sign_y;
// 		}
// 	}
// }



// void drawline(t_fdf *data, t_line line, uint32_t start, uint32_t end)
// {
// 	t_draw	draw;
// 	int		i;
// 	int		j;
// 	int		diff[3];
// 	t_rgb	p[3];
// 	int32_t	color;

// 	draw.delta_x = abs(line.x2 - line.x1);
// 	draw.delta_y = abs(line.y2 - line.y1);
// 	draw.sign_x = (line.x1 < line.x2) ? 1 : -1;
// 	draw.sign_y = (line.y1 < line.y2) ? 1 : -1;
// 	draw.err = draw.delta_x - draw.delta_y;
// 	printf("%d\n", draw.delta_x);
// 	printf("%d\n", draw.delta_y);
// 	printf("%d\n", draw.sign_x);
// 	printf("%d\n", draw.sign_y);
// 	printf("%d\n", draw.err);
// 	float	temp = (float)draw.delta_y / draw.delta_x;
// 	float	k;
// 	printf("%f\n", temp);
// 	i = 0;
// 	k = temp;
// 	while (i < 100)
// 	{
// 		ft_mlx_put_pixel(data, line.x1, line.y1, 0xffffff);
// 		if (line.x1 == line.x2 && line.y1 == line.y2)
// 			break ;
// 		if (draw.delta_x >= draw.delta_y)
// 		{
// 			line.x1 += 1;
// 			line.y1 += k;
// 			k += temp;
// 		}
// 		i++;
// 	}
// }

// void	color_value(uint32_t start, uint32_t end)

void drawline(t_fdf *data, t_line line, uint32_t start, uint32_t end)
{
	t_draw	draw;
	int		i;
	int		color_steps;

	draw.delta_x = abs(line.x2 - line.x1);
	draw.delta_y = abs(line.y2 - line.y1);
	draw.sign_x = (line.x1 < line.x2) ? 1 : -1;
	draw.sign_y = (line.y1 < line.y2) ? 1 : -1;
	draw.err = draw.delta_x - draw.delta_y;
	// printf("dx = %d\n", draw.delta_x);
	// printf("dy = %d\n", draw.delta_y);
	// printf("%d\n", draw.sign_x);
	// printf("%d\n", draw.sign_y);
	// printf("%d\n", draw.err);
	int		diff[3];
	t_rgb	p[3];
	int32_t	color;
	p[0] = int32_to_rgb(start);
	p[1] = int32_to_rgb(end);
	diff[0] = p[1].r - p[0].r;
	diff[1] = p[1].g - p[0].g;
	diff[2] = p[1].b - p[0].b;
	i = 0;
	color_steps = draw.delta_x;
	if (draw.delta_x < draw.delta_y)
		color_steps = draw.delta_y;
	if (color_steps < 1)
		color_steps = 1;
	while (true)
	{
		p[2].r = p[0].r + (diff[0] * i / color_steps);
		p[2].g = p[0].g + (diff[1] * i / color_steps);
		p[2].b = p[0].b + (diff[2] * i / color_steps);
		color = rgb_to_int32(p[2].r, p[2].g, p[2].b, 255);
		// color = rgb_to_int32(255, 255, 0, 255);
		// ft_mlx_put_pixel(data, line.x1, line.y1, LIGHT_CORAL);
		ft_mlx_put_pixel(data, line.x1, line.y1, color);
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
		i++;
	}
	// j = (draw.delta_x < draw.delta_y) ? draw.delta_x : draw.delta_y;
	// printf("i = %d, j = %d\n", i, j);
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
























// void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
// {
// 	t_draw	draw;
// 	int		i;
// 	int		j;
// 	int		diff[3];
// 	t_rgb	p[3];
// 	int32_t	color;


// 	draw.delta_x = abs(x2 - x1);
// 	draw.delta_y = abs(y2 - y1);
// 	draw.sign_x = (x1 < x2) ? 1 : -1;
// 	draw.sign_y = (y1 < y2) ? 1 : -1;
// 	draw.err = draw.delta_x - draw.delta_y;
// 	printf("%d, %d\n", draw.delta_x, draw.delta_y);
// 	while (1)
// 	{
// 		ft_mlx_put_pixel(data, x1, y1, 0xffffff);
// 		if (x1 == x2 && y1 == y2)
// 			break ;
// 		draw.e2 = 2 * draw.err;
// 		if (draw.e2 > -draw.delta_y)
// 		{
// 			draw.err -= draw.delta_y;
// 			x1 += draw.sign_x;
// 		}
// 		if (draw.e2 < draw.delta_x)
// 		{
// 			draw.err += draw.delta_x;
// 			y1 += draw.sign_y;
// 		}
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
			// mlx_put_pixel(data->image, cx, cy, color);
			ft_mlx_put_pixel(data, cx, cy, color);

			
			// mlx_put_pixel(data->image, data->grid[y][x].x, data->grid[y][x].y, 0xffffff);
			// color_buffer[(WIDTH * cy) + cx] = color;
		}
}

void	draw_rect_2(t_fdf *data, t_rect rect)
{
	for (int i = 0; i < rect.width; i++)
		for (int j = 0; j < rect.height; j++)
		{
			int	cx = rect.x + i;
			int	cy = rect.y + j;
			// printf("%d, %d\n", cy, cx);
			// mlx_put_pixel(data->image, cx, cy, color);
			ft_mlx_put_pixel(data, cx, cy, rect.color);

			
			// mlx_put_pixel(data->image, data->grid[y][x].x, data->grid[y][x].y, 0xffffff);
			// color_buffer[(WIDTH * cy) + cx] = color;
		}
}

void	draw_rect_outline(t_fdf *data, t_rect rect, int thickness, uint32_t color)
{
	for (int i = 0; i < rect.width; i++)
		for (int j = 0; j < rect.height; j++)
		{
			int	cx = rect.x + i;
			int	cy = rect.y + j;
			if (cx < rect.x + thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cx >= rect.x + rect.width - thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cy < rect.y + thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
			if (cy >= rect.y + rect.height - thickness)
				ft_mlx_put_pixel(data, cx, cy, color);
		}
}

// void	draw_grid(t_fdf *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;

// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			drawline(data, x, y, x, WIDTH);
// 			x += 20;
// 		}
// 		drawline(data, 0, y, WIDTH, y);
// 		y += 20;
// 	}
// }
