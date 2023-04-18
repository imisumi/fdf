/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/18 02:40:59 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

uint32_t	color_picker(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	//
	draw_rect(data, 0 + x_offset, 0 + y_offset, 136, 136, 255);
	//
	draw_rect(data, 3 + x_offset, 3 + y_offset, 130, 130, 2139062271);
	//	row 1
	draw_rect(data, 5 + x_offset, 5 + y_offset, 30, 30, BRIGHT_RED);
	draw_rect(data, 37 + x_offset, 5 + y_offset, 30, 30, LIGHT_CORAL);
	draw_rect(data, 69 + x_offset, 5 + y_offset, 30, 30, LAVENDER);
	draw_rect(data, 101 + x_offset, 5 + y_offset, 30, 30, TURQUOISE);
	//	row 2
	draw_rect(data, 5 + x_offset, 37 + y_offset, 30, 30, ORANGE);
	draw_rect(data, 37 + x_offset, 37 + y_offset, 30, 30, GOLD);
	draw_rect(data, 69 + x_offset, 37 + y_offset, 30, 30, VANILLA);
	draw_rect(data, 101 + x_offset, 37 + y_offset, 30, 30, OCEAN_BLUE);
	//	row 3
	draw_rect(data, 5 + x_offset, 69 + y_offset, 30, 30, SKY_BLUE);
	draw_rect(data, 37 + x_offset, 69 + y_offset, 30, 30, TEAL);
	draw_rect(data, 69 + x_offset, 69 + y_offset, 30, 30, NAVY_BLUE);
	draw_rect(data, 101 + x_offset, 69 + y_offset, 30, 30, BLACK);
	//	row 4
	draw_rect(data, 5 + x_offset, 101 + y_offset, 30, 30, WHITE);
	draw_rect(data, 37 + x_offset, 101 + y_offset, 30, 30, GREY);
	draw_rect(data, 69 + x_offset, 101 + y_offset, 30, 30, DARK_GREY);
	draw_rect(data, 101 + x_offset, 101 + y_offset, 30, 30, CHARCOAL);

	
	// draw_rect(data, 51 + x_offset, 7 + y_offset, 20, 20, -13421569);

	// draw_rect(data, 73 + x_offset, 7 + y_offset, 20, 20, -13421569);
}