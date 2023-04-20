/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/20 03:44:15 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	is_color_clicked(t_fdf *data, int x, int y, int i)
{
	if (x >= data->color_picker[i].x && x <= data->color_picker[i].x + data->color_picker[i].width && y >= data->color_picker[i].y && y <= data->color_picker[i].y + data->color_picker[i].height)
	{
		return (true);
	}
	// printf("hey\n");
	// printf("x = %d, y = %d\n", data->menu_button[i].x, data->menu_button[i].y);
	// printf("x = %d, y = %d\n", data->menu_button[i].x + data->menu_button[i].width, data->menu_button[i].y + data->menu_button[i].height);
	return (false);
}

void	what_collor_is_clicked(t_fdf **d, int x, int y, int button)
{
	t_fdf	*data;

	data = *d;
	// if (button == 13)
	// {
	// 	if (is_color_clicked(data, x, y, 1) == true)
	// 		data->menu.color = data->color_picker[1].color;
	// 	if (is_color_clicked(data, x, y, 2) == true)
	// 		data->menu.color = data->color_picker[2].color;
	// 	if (is_color_clicked(data, x, y, 3) == true)
	// 		data->menu.color = data->color_picker[3].color;
	// 	if (is_color_clicked(data, x, y, 4) == true)
	// 		data->menu.color = data->color_picker[4].color;
	// 	if (is_color_clicked(data, x, y, 5) == true)
	// 		data->menu.color = data->color_picker[5].color;
	// 	if (is_color_clicked(data, x, y, 6) == true)
	// 		data->menu.color = data->color_picker[6].color;
	// 	if (is_color_clicked(data, x, y, 7) == true)
	// 		data->menu.color = data->color_picker[7].color;
	// 	if (is_color_clicked(data, x, y, 8) == true)
	// 		data->menu.color = data->color_picker[8].color;
	// 	if (is_color_clicked(data, x, y, 9) == true)
	// 		data->menu.color = data->color_picker[9].color;
	// 	if (is_color_clicked(data, x, y, 10) == true)
	// 		data->menu.color = data->color_picker[10].color;
	// 	if (is_color_clicked(data, x, y, 11) == true)
	// 		data->menu.color = data->color_picker[11].color;
	// 	if (is_color_clicked(data, x, y, 12) == true)
	// 		data->menu.color = data->color_picker[12].color;
	// 	if (is_color_clicked(data, x, y, 13) == true)
	// 		data->menu.color = data->color_picker[13].color;
	// 	if (is_color_clicked(data, x, y, 14) == true)
	// 		data->menu.color = data->color_picker[14].color;
	// 	if (is_color_clicked(data, x, y, 15) == true)
	// 		data->menu.color = data->color_picker[15].color;
	// 	if (is_color_clicked(data, x, y, 16) == true)
	// 		data->menu.color = data->color_picker[16].color;
	// }

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
	data->menu_button[14].color = data->menu_button[0].color;
	data->color_picker[0].active = false;
}

uint32_t	current_color(int i)
{
	uint32_t	colors[16];

	colors[0] = BRIGHT_RED;
	colors[1] = LIGHT_CORAL;
	colors[2] = LAVENDER;
	colors[3] = TURQUOISE;
	colors[4] = ORANGE;
	colors[5] = GOLD;
	colors[6] = VANILLA;
	colors[7] = OCEAN_BLUE;
	colors[8] = SKY_BLUE;
	colors[9] = TEAL;
	colors[10] = NAVY_BLUE;
	colors[11] = BLACK;
	colors[12] = WHITE;
	colors[13] = GREY;
	colors[14] = DARK_GREY;
	colors[15] = CHARCOAL;
	return (colors[i]);
}

void	render_color_picker(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		draw_rect(data,
			data->color_picker[i].x,
			data->color_picker[i].y,
			data->color_picker[i].width,
			data->color_picker[i].height,
			data->color_picker[i].color
			);
		i++;
	}
}

// t_rect	set_rect_value(int x, int y, int w, int h, uint32_t c)
// {
// 	t_rect	rect;

// 	rect.x = x;
// 	rect.y = y;
// 	rect.width = w;
// 	rect.height = h;
// 	rect.color = c;
// 	return (rect);
// }

t_rect	set_rect_value(t_picker p, int x_offset, int y_offset, int first)
{
	t_rect	rect;

	if (first == 1)
	{
		rect.x = x_offset - p.outline;
		rect.y = y_offset - p.outline;
		rect.width = p.border;
		rect.height = p.border;
		rect.color = 555819519;
		return (rect);
	}
	rect.x = p.x_start + x_offset;
	rect.y = p.y_start + y_offset;
	rect.width = p.size;
	rect.height = p.size;
	rect.color = current_color((p.i * 4) + p.j);
	return (rect);
}

void	init_color_picker(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf		*data;
	t_picker	p;

	data = *d;
	p.size = 30;
	p.spacing = 3;
	p.outline = 3;
	p.border = (p.size * 4) + (p.spacing * 4) + p.outline;
	data->color_picker[0] = set_rect_value(p, x_offset, y_offset, 1);
	p.i = 0;
	p.y_start = 0;
	while (p.i < 4)
	{
		p.j = 0;
		p.x_start = 0;
		while (p.j < 4)
		{
			data->color_picker[(p.i * 4) + p.j + 1] = set_rect_value(p, \
				x_offset, y_offset, 0);
			p.x_start += (p.size + p.spacing);
			p.j++;
		}
		p.y_start += (p.size + p.spacing);
		p.i++;
	}
}
