/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:51:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/29 14:43:55 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

void	fill_background(t_fdf *data)
{
	int		i;
	int		j;
	int		diff[3];
	t_rgb	col[3];
	int32_t	color;

	col[0] = int32_to_rgb(data->menu_button[18].color);
	col[1] = int32_to_rgb(data->menu_button[19].color);
	calculate_diff(diff, col);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		col[2].r = col[0].r + (diff[0] * i / HEIGHT);
		col[2].g = col[0].g + (diff[1] * i / HEIGHT);
		col[2].b = col[0].b + (diff[2] * i / HEIGHT);
		color = rgb_to_int32(col[2].r, col[2].g, col[2].b, 255);
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
	int			i;
	int			diff[3];
	t_rgb		col[3];
	uint32_t	*color;

	color = malloc(sizeof(uint32_t) * steps);
	if (!color)
		exit(EXIT_FAILURE);
	col[0] = int32_to_rgb(c1);
	col[1] = int32_to_rgb(c2);
	diff[0] = col[1].r - col[0].r;
	diff[1] = col[1].g - col[0].g;
	diff[2] = col[1].b - col[0].b;
	i = 0;
	while (i < steps)
	{
		col[2].r = col[0].r + (diff[0] * i / steps);
		col[2].g = col[0].g + (diff[1] * i / steps);
		col[2].b = col[0].b + (diff[2] * i / steps);
		color[i] = rgb_to_int32(col[2].r, col[2].g, col[2].b, 255);
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
	if (!y_level)
		exit(EXIT_FAILURE);
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

void	set_grid_colors(t_fdf **d)
{
	t_fdf		*data;
	uint32_t	*gradient;
	int			*y_level;
	int			steps;
	int			xy[2];

	data = *d;
	y_level = lowest_heighest_y(data);
	steps = y_level[1] - y_level[0] + 1;
	gradient = get_gradient(steps, data->menu_button[16].color, \
		data->menu_button[17].color);
	xy[1] = 0;
	while (xy[1] < data->height)
	{
		xy[0] = 0;
		while (xy[0] < data->width)
		{
			y_level[1] = abs(y_level[0] - data->map[xy[1]][xy[0]]);
			data->map_colors[xy[1]][xy[0]] = gradient[y_level[1]];
			xy[0]++;
		}
		xy[1]++;
	}
	free(gradient);
	free(y_level);
}
