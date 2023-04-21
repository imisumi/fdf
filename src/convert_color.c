/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/21 18:06:18 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	rgb_to_int32(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	hexstr_to_int32(char *str)
{
	int			i;
	int			value;
	char		c;
	uint32_t	result;

	if (str[0] != '0' && str[1] != 'x')
		return (0);
	i = 2;
	while (str[i])
	{
		c = str[i];
		if (c >= '0' && c <= '9')
			value = c - '0';
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		else
			return (0);
		result = (result << 4) | value;
		i++;
	}
	result = (result << 4) | 15;
	result = (result << 4) | 15;
	return (result);
}

t_rgb	hex_to_rgb(int hex)
{
	t_rgb	rgb;

	rgb.r = (hex >> 16) & 0xFF;
	rgb.g = (hex >> 8) & 0xFF;
	rgb.b = hex & 0xFF;
	rgb.a = 255;
	return (rgb);
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
