/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:51:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/19 17:09:28 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

void	temps(void)
{
	uint8_t		col;
	uint32_t	start;

	start = NAVY_BLUE;
	col = (start >> 24);
}

uint8_t	*int_32_to_8(uint32_t color)
{
	uint8_t	colors[4];

	colors[0] = (color >> 24);
	colors[1] = (color >> 16);
	colors[2] = (color >> 8);
	colors[3] = color;
	return (colors);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
