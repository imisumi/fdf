/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/25 16:54:13 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	menu_location(t_fdf **d, int x_offset, int y_offset)
// {
// 	t_fdf	*data;

// 	data = *d;
// 	ft_mlx_put_string(data, "Location", 0 + x_offset, 0 + y_offset);
// 	char str[64];
// 	sprintf(str, "X	%.2f", data->move.x);
// 	ft_mlx_put_string(data, str, 0 + x_offset, 20 + y_offset);
// 	sprintf(str, "Y	%.2f", data->move.y);
// 	ft_mlx_put_string(data, str, 0 + x_offset, 40 + y_offset);
// 	sprintf(str, "Z	%.2f", data->move.z);
// 	ft_mlx_put_string(data, str, 0 + x_offset, 60 + y_offset);
// }

void	menu_location(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	char str[64];
	ft_mlx_put_string(data, "Camera	position", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	X	%.2f", data->camera.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	sprintf(str, "[	]	Y	%.2f", data->camera.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	sprintf(str, "[	]	Z	%.2f", data->camera.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_rotation(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	char str[64];
	ft_mlx_put_string(data, "Rotation", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	X	%.2f", data->rotation.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	sprintf(str, "[	]	Y	%.2f", data->rotation.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	sprintf(str, "[	]	Z	%.2f", data->rotation.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_origin(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	char str[64];
	ft_mlx_put_string(data, "Origin	point", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	X	%.2f", data->origin.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	sprintf(str, "[	]	Y	%.2f", data->origin.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	sprintf(str, "[	]	Z	%.2f", data->origin.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_scale(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	char str[64];
	ft_mlx_put_string(data, "Scale", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	%.2f", data->scale);
	if (data->scale != 1000)
		sprintf(str, "[R]	%.2f", data->scale);
	else
		sprintf(str, "[	]	%.2f", data->scale);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
}


void	menu_view(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "Projection", 0 + x_offset, 0 + y_offset);
	if (data->perspective == true)
		ft_mlx_put_string(data, "[X]	Perspective", 0 + x_offset, 25 + y_offset);
	else
		ft_mlx_put_string(data, "[	]	Perspective", 0 + x_offset, 25 + y_offset);
	if (data->parallel == true)
		ft_mlx_put_string(data, "[X]	Parallel", 0 + x_offset, 45 + y_offset);
	else
		ft_mlx_put_string(data, "[	]	Parallel", 0 + x_offset, 45 + y_offset);
	if (data->isometric == true)
		ft_mlx_put_string(data, "[X]	Isometic", 0 + x_offset, 65 + y_offset);
	else
		ft_mlx_put_string(data, "[	]	Isometic", 0 + x_offset, 65 + y_offset);

}

void	menu_colors(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	char str[64];
	ft_mlx_put_string(data, "Colors", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	%.2f", data->scale);
	// sprintf(str, "Menu%.", data->scale);
	ft_mlx_put_string(data, "[	]	Menu", 0 + x_offset, 25 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Grid", 0 + x_offset, 45 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Background", 0 + x_offset, 65 + y_offset);
}

void	draw_menu(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "*********************", 30, 20);
	ft_mlx_put_string(data, "***	FDF	-	imisumi	***", 30, 40);
	ft_mlx_put_string(data, "*********************", 30, 60);
	// ft_mlx_put_string(data, "[	]", 5, 65);
	// ft_mlx_put_string(data, "[X]", 5, 85);
	menu_location(&data, 40, 120);
	menu_rotation(&data, 40, 220);
	menu_origin(&data, 40, 320);
	menu_scale(&data, 40, 420);
	menu_view(&data, 40, 480);
	menu_colors(&data, 40, 580);
}

	// int startColor[] = {205, 92, 92};
	// int endColor[] = {100, 149, 237};

// void	fill_background(t_fdf *data)
// {
// 	int			i;
// 	int			j;
// 	int			diff[3];
// 	t_rgb		p[3];
// 	uint16_t	color;

// 	p[0] = ft_pixel_2(CHARCOAL);
// 	p[1] = ft_pixel_2(OCEAN_BLUE);
// 	diff[0] = p[1].r - p[0].r;
// 	diff[1] = p[1].g - p[0].g;
// 	diff[2] = p[1].b - p[0].b;
// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		p[2].r = p[0].r + (diff[0] * i / HEIGHT);
// 		p[2].g = p[0].g + (diff[1] * i / HEIGHT);
// 		p[2].b = p[0].b + (diff[2] * i / HEIGHT);
// 		color = ft_pixel(p[2].r, p[2].g, p[2].b, 255);
// 		while (j < WIDTH)
// 		{
// 			ft_mlx_put_pixel(data, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }