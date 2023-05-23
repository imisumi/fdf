/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:10:54 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/23 16:01:21 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// menu color
// grid colors
void	is_mg_clicked(t_fdf *data, int x, int y)
{
	if (is_menu_button_clicked(data, x, y, 15) == true)
	{
		init_color_picker(&data, x, y);
		data->color_picker[0].active = true;
		data->button = 0;
	}
	if (is_menu_button_clicked(data, x, y, 16) == true)
	{
		init_color_picker(&data, x, y);
		data->color_picker[0].active = true;
		data->button = 16;
		data->color_switch = true;
	}
	if (is_menu_button_clicked(data, x, y, 17) == true)
	{
		init_color_picker(&data, x, y);
		data->color_picker[0].active = true;
		data->button = 17;
		data->color_switch = true;
	}
}

void	is_projection_clicked(t_fdf *data, int x, int y)
{
	if (is_menu_button_clicked(data, x, y, 12) == true)
	{
		data->perspective = true;
		data->parallel = false;
		data->isometric = false;
	}
	if (is_menu_button_clicked(data, x, y, 13) == true)
	{
		data->perspective = false;
		data->parallel = true;
		data->isometric = false;
	}
	if (is_menu_button_clicked(data, x, y, 14) == true)
	{
		data->perspective = false;
		data->parallel = false;
		data->isometric = true;
	}
}
