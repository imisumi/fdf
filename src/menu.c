/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/02 14:56:36 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu_position(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Camera	position", 0 + x_offset, 0 + y_offset);
	if (data->camera.x != 0)
		sprintf(str, "[R]	X	%.2f", data->camera.x);
	else
		sprintf(str, "[	]	X	%.2f", data->camera.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	if (data->camera.y != 0)
		sprintf(str, "[R]	Y	%.2f", data->camera.y);
	else
		sprintf(str, "[	]	Y	%.2f", data->camera.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	if (data->camera.z != data->width)
		sprintf(str, "[R]	Z	%.2f", data->camera.z);
	else
		sprintf(str, "[	]	Z	%.2f", data->camera.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_rotation(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Rotation", 0 + x_offset, 0 + y_offset);
	if (data->rotation.x != 0)
		sprintf(str, "[R]	X	%.2f", data->rotation.x);
	else
		sprintf(str, "[	]	X	%.2f", data->rotation.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	if (data->rotation.y != 0)
		sprintf(str, "[R]	Y	%.2f", data->rotation.y);
	else
		sprintf(str, "[	]	Y	%.2f", data->rotation.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	if (data->rotation.z != 0)
		sprintf(str, "[R]	Z	%.2f", data->rotation.z);
	else
		sprintf(str, "[	]	Z	%.2f", data->rotation.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_origin(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Origin	point", 0 + x_offset, 0 + y_offset);
	if (data->origin.x != (float)(data->width - 1) / 2.00f)
		sprintf(str, "[R]	x	%.2f", data->origin.x);
	else
		sprintf(str, "[	]	x	%.2f", data->origin.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
	if (data->origin.y != (float)(data->height - 1) / 2.00f)
		sprintf(str, "[R]	y	%.2f", data->origin.y);
	else
		sprintf(str, "[	]	y	%.2f", data->origin.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 45 + y_offset);
	if (data->origin.z != 0)
		sprintf(str, "[R]	Z	%.2f", data->origin.z);
	else
		sprintf(str, "[	]	Z	%.2f", data->origin.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 65 + y_offset);
}

void	menu_scale(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Scale", 0 + x_offset, 0 + y_offset);
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
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Colors", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	%.2f", data->scale);
	// sprintf(str, "Menu%.", data->scale);
	ft_mlx_put_string(data, "[	]	Menu", 0 + x_offset, 25 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Grid", 0 + x_offset, 45 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Background", 0 + x_offset, 65 + y_offset);
}

void	menu_flatten(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Flatten", 0 + x_offset, 0 + y_offset);
	if (data->flatten != 1)
		sprintf(str, "[R]	%.2f", data->flatten);
	else
		sprintf(str, "[	]	%.2f", data->flatten);
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
}

void	draw_menu(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "*********************", 30, 20);
	ft_mlx_put_string(data, "***	FDF	-	imisumi	***", 30, 40);
	ft_mlx_put_string(data, "*********************", 30, 60);
	menu_position(&data, 40, 120);
	menu_rotation(&data, 40, 220);
	menu_origin(&data, 40, 320);
	menu_scale(&data, 40, 420);
	menu_flatten(&data,40, 480);
	menu_view(&data, 40, 540);
	menu_colors(&data, 40, 640);
}
