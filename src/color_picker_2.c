/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/22 15:28:07 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	is_color_clicked(t_fdf *data, int x, int y, int i)
{
	if (x >= data->color_picker[i].x && x <= data->color_picker[i].x + \
		data->color_picker[i].width && y >= data->color_picker[i].y && \
		y <= data->color_picker[i].y + data->color_picker[i].height)
	{
		return (true);
	}
	return (false);
}

void	what_collor_is_clicked_2(t_fdf *data, int x, int y, int button)
{
	if (is_color_clicked(data, x, y, 11) == true)
		data->menu_button[button].color = data->color_picker[11].color;
	if (is_color_clicked(data, x, y, 12) == true)
		data->menu_button[button].color = data->color_picker[12].color;
	if (is_color_clicked(data, x, y, 13) == true)
		data->menu_button[button].color = data->color_picker[13].color;
	if (is_color_clicked(data, x, y, 14) == true)
		data->menu_button[button].color = data->color_picker[14].color;
	if (is_color_clicked(data, x, y, 15) == true)
		data->menu_button[button].color = data->color_picker[15].color;
	if (is_color_clicked(data, x, y, 16) == true)
		data->menu_button[button].color = data->color_picker[16].color;
	data->menu_button[15].color = data->menu_button[0].color;
	data->color_picker[0].active = false;
}

void	what_collor_is_clicked(t_fdf **d, int x, int y, int button)
{
	t_fdf	*data;

	data = *d;
	if (is_color_clicked(data, x, y, 1) == true)
		data->menu_button[button].color = data->color_picker[1].color;
	if (is_color_clicked(data, x, y, 2) == true)
		data->menu_button[button].color = data->color_picker[2].color;
	if (is_color_clicked(data, x, y, 3) == true)
		data->menu_button[button].color = data->color_picker[3].color;
	if (is_color_clicked(data, x, y, 4) == true)
		data->menu_button[button].color = data->color_picker[4].color;
	if (is_color_clicked(data, x, y, 5) == true)
		data->menu_button[button].color = data->color_picker[5].color;
	if (is_color_clicked(data, x, y, 6) == true)
		data->menu_button[button].color = data->color_picker[6].color;
	if (is_color_clicked(data, x, y, 7) == true)
		data->menu_button[button].color = data->color_picker[7].color;
	if (is_color_clicked(data, x, y, 8) == true)
		data->menu_button[button].color = data->color_picker[8].color;
	if (is_color_clicked(data, x, y, 9) == true)
		data->menu_button[button].color = data->color_picker[9].color;
	if (is_color_clicked(data, x, y, 10) == true)
		data->menu_button[button].color = data->color_picker[10].color;
	what_collor_is_clicked_2(data, x, y, button);
}
