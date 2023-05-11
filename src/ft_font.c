/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_font.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:01:37 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/05/11 17:05:14 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

static void	ft_mlx_draw_char(t_fdf *data, int32_t texoffset, int32_t imgoffset, int32_t x_ofset, int32_t yy)
{
	char	*pixelx;
	uint8_t	*pixeli;

	if (texoffset < 0)
		return;
	for (uint32_t y = 0; y < FONT_HEIGHT; y++)
	{
		pixelx = &font_atlas.pixels[(y * font_atlas.width + texoffset) * BPP];
		pixeli = data->image->pixels + ((y * data->image->width + imgoffset) * BPP);
		for (uint32_t x = 0; x < FONT_WIDTH; x++)
		{
			uint32_t pixel_offset = x * BPP;
			uint32_t x_pos = imgoffset + x;
			uint32_t y_pos = y;
			uint8_t red = *(pixelx + pixel_offset);
			uint8_t green = *(pixelx + pixel_offset + 1);
			uint8_t blue = *(pixelx + pixel_offset + 2);
			
			uint8_t alpha = *(pixelx + pixel_offset + 3);
			// printf("%d\n", rgb_to_int32(123, green, blue, alpha));
			if (alpha > 155)
			{
				// printf("%d\n", rgb_to_int32(123, green, blue, alpha));
				mlx_put_pixel(data->image, x_pos + x_ofset, y_pos + yy, ((255 << 24) | (green << 16) | (blue << 8) | alpha));
				// mlx_put_pixel(data->image, x_pos + x_ofset, y_pos + yy, 0xFFFFFF);
			}
		}
	}
}

const mlx_texture_t	*ft_mlx_get_font(void)
{
	return ((const mlx_texture_t*)&font_atlas);
}

int32_t	ft_mlx_get_texoffset(char c)
{
	bool	_isprint;

	_isprint = isprint(c);
	return (-1 * !_isprint + ((FONT_WIDTH + 2) * (c - 32)) * _isprint);
}

void	ft_mlx_put_string(t_fdf *data, const char *str, int x, int y)
{
	int32_t	imgoffset;
	size_t	i;
	size_t	len;

	imgoffset = 0;
	len = ft_strlen(str);
	if (len > MLX_MAX_STRING)
		return ;
	i = 0;
	while (i < len)
	{
		ft_mlx_draw_char(data, ft_mlx_get_texoffset(str[i]), imgoffset, x, y);
		i++;
		imgoffset += FONT_WIDTH;
	}
}
