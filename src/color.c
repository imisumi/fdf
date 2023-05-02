/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:51:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/02 13:15:47 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

// int32_t	rgb_to_int32(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

// uint32_t	hex_to_int32(int hex)
// {
// 	t_rgb	c;

// 	c.r = (hex >> 16) & 0xFF;
// 	c.g = (hex >> 8) & 0xFF;
// 	c.b = hex & 0xFF;
// 	return (rgb_to_int32(c.r, c.g, c.b, 255));
// }

// t_rgb	int32_to_rgb(uint32_t pixel_value)
// {
// 	t_rgb	pixel;

// 	pixel.r = (pixel_value >> 24) & 0xFF;
// 	pixel.g = (pixel_value >> 16) & 0xFF;
// 	pixel.b = (pixel_value >> 8) & 0xFF;
// 	pixel.a = pixel_value & 0xFF;
// 	return (pixel);
// }

void	fill_background(t_fdf *data)
{
	int		i;
	int		j;
	int		diff[3];
	t_rgb	p[3];
	int32_t	color;

	// p[0] = ft_pixel_2(CHARCOAL);
	// p[1] = ft_pixel_2(OCEAN_BLUE);
	p[0] = int32_to_rgb(data->menu_button[18].color);
	p[1] = int32_to_rgb(data->menu_button[19].color);
	diff[0] = p[1].r - p[0].r;
	diff[1] = p[1].g - p[0].g;
	diff[2] = p[1].b - p[0].b;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		p[2].r = p[0].r + (diff[0] * i / HEIGHT);
		p[2].g = p[0].g + (diff[1] * i / HEIGHT);
		p[2].b = p[0].b + (diff[2] * i / HEIGHT);
		color = rgb_to_int32(p[2].r, p[2].g, p[2].b, 255);
		while (j < WIDTH)
		{
			ft_mlx_put_pixel(data, j, i, color);
			j++;
		}
		i++;
	}
}

uint32_t	*get_gradient(int steps, uint32_t c1, uint32_t c2)
{
	int		i;
	int		diff[3];
	t_rgb	p[3];
	uint32_t	*color;

	color = malloc(sizeof(uint32_t) * steps);
	p[0] = int32_to_rgb(c1);
	p[1] = int32_to_rgb(c2);
	diff[0] = p[1].r - p[0].r;
	diff[1] = p[1].g - p[0].g;
	diff[2] = p[1].b - p[0].b;
	i = 0;
	while (i < steps)
	{
		p[2].r = p[0].r + (diff[0] * i / steps);
		p[2].g = p[0].g + (diff[1] * i / steps);
		p[2].b = p[0].b + (diff[2] * i / steps);
		color[i] = rgb_to_int32(p[2].r, p[2].g, p[2].b, 255);
		i++;
	}
	return (color);
}

int	*lowest_heighest_y(t_fdf *data)
{
	int	*y_level;
	int	x;
	int	y;

	y_level = malloc(sizeof(int) * 2);
	y_level[0] = data->map[0][0];
	y_level[1] = data->map[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] > y_level[1])
				y_level[1] = data->map[y][x];
			if (data->map[y][x] < y_level[0])
				y_level[0] = data->map[y][x];
			x++;
		}
		y++;
	}
	return (y_level);
}

int	heighest_y(t_fdf *data)
{
	int	y_level;
	int	x;
	int	y;

	y_level = data->map[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] > y_level)
				y_level = data->map[y][x];
			x++;
		}
		y++;
	}
	return (y_level);
}

int	dif_num(int one, int two)
{
	int	i;

	i = 0;
	while (one < two)
	{
		one++;
		i++;
	}
	return (i);
}

void	set_grid_colors(t_fdf **d)
{
	t_fdf		*data;
	uint32_t	*gradient;
	int			*y_level;
	int		steps;
	int		x;
	int		y;

	data = *d;
	y_level = lowest_heighest_y(data);
	steps = y_level[1] - y_level[0] + 1;
	gradient = get_gradient(steps, data->menu_button[16].color, data->menu_button[17].color);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			y_level[1] = abs(y_level[0] - data->map[y][x]);
			data->map_colors[y][x] = gradient[y_level[1]];
			x++;
		}
		y++;
	}
	free(gradient);
	free(y_level);
}
