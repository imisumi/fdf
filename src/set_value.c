/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/01 16:20:17 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_data_value_2(t_fdf *data)
{

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
	data->menu_button[19].color = LIGHT_CORAL;
	// data->menu_button[18].color = hex_to_int32(0xFF0000);

	data->flatten = 1.00f;

	data->angle = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->move.z = 0;
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
	// printf("%d\n", data->width);
	data->origin.x = (float)(data->width - 1) / 2.00f;
	data->origin.y = (float)(data->height - 1) / 2.00f;
	// data->origin.x = 2.5f;
	// data->origin.y = 2.5f;
	data->origin.z = 0;

	data->color_picker[0].active = false;

	data->perspective = false;
	data->parallel = false;
	data->isometric = true;




	// set_data_value_2(data);
}