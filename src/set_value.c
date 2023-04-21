/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/20 19:24:59 by ichiro           ###   ########.fr       */
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
	data->menu.x = 0;
	data->menu.y = 0;
	data->menu.width = 270;
	data->menu.height = HEIGHT;
	data->menu.color = OCEAN_BLUE;
	data->menu_button[0].color = OCEAN_BLUE;
	data->menu_button[14].color = data->menu_button[0].color;
	data->text = ORANGE;

	data->menu_button[17].color = SKY_BLUE;
	data->menu_button[18].color = OCEAN_BLUE;
	// data->menu_button[18].color = hex_to_int32(0xFF0000);

	data->angle = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->move.z = 0;
	data->rotation.x = 0;
	data->rotation.y = 0;
	data->rotation.z = 0;
	data->camera.x = 0;
	data->camera.y = 0;
	data->camera.z = 20;
	data->scale = 500.0f;
	data->origin.x = (float)data->width / 2;
	data->origin.y = (float)data->height / 2;
	data->origin.z = 0;

	data->color_picker[0].active = false;

	data->perspective = false;
	data->parallel = false;
	data->isometric = true;




	// set_data_value_2(data);
}
