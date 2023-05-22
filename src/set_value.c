/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/22 16:07:49 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_data_value_2(t_fdf *data)
{
	data->flatten = 1.00f;
	data->angle = 0;
	data->rotation.x = 0;
	data->rotation.y = 0;
	data->rotation.z = 0;
	data->camera.x = 0;
	data->camera.y = 0;
	if (data->width > data->height)
		data->camera.z = data->width;
	else
		data->camera.z = data->height;
	data->scale = 1000.00f;
	data->origin.x = (float)(data->width - 1) / 2.00f;
	data->origin.y = (float)(data->height - 1) / 2.00f;
	data->origin.z = 0;
	data->color_picker[0].active = false;
	data->perspective = false;
	data->parallel = false;
	data->isometric = true;
}

void	set_data_value(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	data->menu_button[0].x = 0;
	data->menu_button[0].y = 0;
	data->menu_button[0].width = 270;
	data->menu_button[0].height = HEIGHT;
	data->menu.x = 0;
	data->menu.y = 0;
	data->menu.width = 270;
	data->menu.height = HEIGHT;
	data->menu.color = OCEAN_BLUE;
	data->menu_button[0].color = OCEAN_BLUE;
	data->menu_button[15].color = data->menu_button[0].color;
	data->text = ORANGE;
	data->color_switch = false;
	data->menu_button[16].color = OCEAN_BLUE;
	data->menu_button[17].color = OCEAN_BLUE;
	data->menu_button[18].color = SKY_BLUE;
	data->menu_button[19].color = OCEAN_BLUE;
	set_data_value_2(data);
}

void	set_button_pos(t_fdf **d, int i, int y)
{
	int		mod;
	t_fdf	*data;

	data = *d;
	mod = 0;
	while (i < 20)
	{
		data->menu_button[i].x = 43;
		data->menu_button[i].y = y;
		data->menu_button[i].width = 24;
		data->menu_button[i].height = 15;
		if (i == 10 || i == 11)
			mod = i - 9;
		if (i % 3 == mod)
			y += 40;
		y += 20;
		i++;
	}
	data->menu_button[17].x = 83;
	data->menu_button[17].y = 689;
	data->menu_button[18].y = 709;
	data->menu_button[19].x = 83;
	data->menu_button[19].y = 709;
}
