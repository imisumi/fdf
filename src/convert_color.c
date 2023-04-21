/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/20 19:16:35 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	rgb_to_int32(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	hex_to_int32(int hex)
{
	t_rgb	c;

	c.r = (hex >> 16) & 0xFF;
	c.g = (hex >> 8) & 0xFF;
	c.b = hex & 0xFF;
	return (rgb_to_int32(c.r, c.g, c.b, 255));
}

t_rgb	int32_to_rgb(uint32_t pixel_value)
{
	t_rgb	pixel;

	pixel.r = (pixel_value >> 24) & 0xFF;
	pixel.g = (pixel_value >> 16) & 0xFF;
	pixel.b = (pixel_value >> 8) & 0xFF;
	pixel.a = pixel_value & 0xFF;
	return (pixel);
}
