/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:51:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/20 02:20:06 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_rgb	ft_pixel_2(uint32_t pixel_value)
{
	t_rgb	pixel;

	pixel.r = (pixel_value >> 24) & 0xFF;
	pixel.g = (pixel_value >> 16) & 0xFF;
	pixel.b = (pixel_value >> 8) & 0xFF;
	pixel.a = pixel_value & 0xFF;
	return (pixel);
}

void	fill_background(t_fdf *data)
{
	int		i;
	int		j;
	int		diff[3];
	t_rgb	p[3];
	int32_t	color;

	p[0] = ft_pixel_2(CHARCOAL);
	p[1] = ft_pixel_2(OCEAN_BLUE);
	diff[0] = p[1].r - p[0].r;
	diff[1] = p[1].g - p[0].g;
	diff[2] = p[1].b - p[0].b;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		p[2].r = p[0].r + (diff[0] * i / HEIGHT);
		p[2].g = p[0].g + (diff[1] * i / HEIGHT);
		p[2].b = p[0].b + (diff[2] * i / HEIGHT);
		color = ft_pixel(p[2].r, p[2].g, p[2].b, 255);
		while (j < WIDTH)
		{
			ft_mlx_put_pixel(data, j, i, color);
			j++;
		}
		i++;
	}
}
