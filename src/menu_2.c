/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/23 16:32:10 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu_view(t_fdf **d, int x_offset, int y_off)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "Projection", 0 + x_offset, 0 + y_off);
	if (data->perspective == true)
		ft_mlx_put_string(data, "[X]	Perspective", 0 + x_offset, 25 + y_off);
	else
		ft_mlx_put_string(data, "[	]	Perspective", 0 + x_offset, 25 + y_off);
	if (data->parallel == true)
		ft_mlx_put_string(data, "[X]	Parallel", 0 + x_offset, 45 + y_off);
	else
		ft_mlx_put_string(data, "[	]	Parallel", 0 + x_offset, 45 + y_off);
	if (data->isometric == true)
		ft_mlx_put_string(data, "[X]	Isometic", 0 + x_offset, 65 + y_off);
	else
		ft_mlx_put_string(data, "[	]	Isometic", 0 + x_offset, 65 + y_off);
}

void	menu_colors(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;
	char	str[64];

	data = *d;
	ft_mlx_put_string(data, "Colors", 0 + x_offset, 0 + y_offset);
	sprintf(str, "[	]	%.2f", data->scale);
	ft_mlx_put_string(data, "[	]	Menu", 0 + x_offset, 25 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Grid", 0 + x_offset, 45 + y_offset);
	ft_mlx_put_string(data, "[	]	[	]	Background", 0 + x_offset, \
		65 + y_offset);
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

void	draw_menu_color_select(t_fdf *data)
{
	draw_rect(data, data->menu_button[15]);
	draw_rect_outline(data, data->menu_button[15], 2, BLACK);
	draw_rect(data, data->menu_button[16]);
	draw_rect_outline(data, data->menu_button[16], 2, BLACK);
	draw_rect(data, data->menu_button[17]);
	draw_rect_outline(data, data->menu_button[17], 2, BLACK);
	draw_rect(data, data->menu_button[18]);
	draw_rect_outline(data, data->menu_button[18], 2, BLACK);
	draw_rect(data, data->menu_button[19]);
	draw_rect_outline(data, data->menu_button[19], 2, BLACK);
}
