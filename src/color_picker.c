/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/22 15:55:36 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	int		i;
	t_rect	rect;

	i = 0;
	while (i < 17)
	{
		rect.x = data->color_picker[i].x;
		rect.y = data->color_picker[i].y;
		rect.width = data->color_picker[i].width;
		rect.height = data->color_picker[i].height;
		rect.color = data->color_picker[i].color;
		draw_rect(data, rect);
		i++;
	}
}

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
