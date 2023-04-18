/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/18 23:20:44 by ichiro           ###   ########.fr       */
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
	ft_mlx_put_string(data, str, 0 + x_offset, 25 + y_offset);
}


void	menu_view(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "View", 0 + x_offset, 0 + y_offset);
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

void	draw_menu(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "*********************", 20, 20);
	ft_mlx_put_string(data, "***	FDF	-	imisumi	***", 20, 40);
	ft_mlx_put_string(data, "*********************", 20, 60);
	// ft_mlx_put_string(data, "[	]", 5, 65);
	// ft_mlx_put_string(data, "[X]", 5, 85);
	menu_location(&data, 20, 150);
	menu_rotation(&data, 20, 250);
	menu_origin(&data, 20, 350);
	menu_scale(&data, 20, 450);
	menu_view(&data, 20, 510);
}