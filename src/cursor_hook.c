/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:10:54 by imisumi           #+#    #+#             */
/*   Updated: 2023/06/04 18:41:34 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	is_menu_button_clicked(t_fdf *data, int x, int y, int i)
{
	if (x >= data->menu_button[i].x && x <= data->menu_button[i].x + \
		data->menu_button[i].width && y >= data->menu_button[i].y && \
		y <= data->menu_button[i].y + data->menu_button[i].height)
	{
		return (true);
	}
	return (false);
}

void	is_background_clicked(t_fdf *data, int x, int y)
{
	if (is_menu_button_clicked(data, x, y, 18) == true)
	{
		init_color_picker(&data, x, y);
		data->color_picker[0].active = true;
		data->button = 18;
	}
	if (is_menu_button_clicked(data, x, y, 19) == true)
	{
		init_color_picker(&data, x, y);
		data->color_picker[0].active = true;
		data->button = 19;
	}
}

void	is_cros_clicked(t_fdf *data, int x, int y)
{
	if (is_menu_button_clicked(data, x, y, 1) == true)
		data->camera.x = 0;
	if (is_menu_button_clicked(data, x, y, 2) == true)
		data->camera.y = 0;
	if (is_menu_button_clicked(data, x, y, 3) == true)
		data->camera.z = data->width;
	if (is_menu_button_clicked(data, x, y, 4) == true)
		data->rotation.x = 0;
	if (is_menu_button_clicked(data, x, y, 5) == true)
		data->rotation.y = 0;
	if (is_menu_button_clicked(data, x, y, 6) == true)
		data->rotation.z = 0;
	if (is_menu_button_clicked(data, x, y, 7) == true)
		data->origin.x = (float)(data->width - 1) / 2.00f;
	if (is_menu_button_clicked(data, x, y, 8) == true)
		data->origin.y = (float)(data->height - 1) / 2.00f;
	if (is_menu_button_clicked(data, x, y, 9) == true)
		data->origin.z = 0;
	if (is_menu_button_clicked(data, x, y, 10) == true)
		data->scale = 1000;
	if (is_menu_button_clicked(data, x, y, 11) == true)
		data->flatten = 1.00f;
}

void	ft_cursor_hook(mouse_key_t button, action_t action, \
	modifier_key_t mods, void *param)
{
	t_fdf	*data;
	int32_t	x;
	int32_t	y;

	(void)button;
	(void)mods;
	data = param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (action == 0 && data->color_picker[0].active == true)
	{
		if (x < data->color_picker[0].x || x > data->color_picker[0].x + \
			data->color_picker[0].width || y < data->color_picker[0].y || \
			y > data->color_picker[0].y + data->color_picker[0].height)
			data->color_picker[0].active = false;
		what_collor_is_clicked(&data, x, y, data->button);
		return ;
	}
	if (action == 0)
	{
		is_cros_clicked(data, x, y);
		is_projection_clicked(data, x, y);
		is_mg_clicked(data, x, y);
		is_background_clicked(data, x, y);
	}
}
