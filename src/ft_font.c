/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_font.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:01:37 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/04/15 00:37:03 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"
//= Private =//

/**
 * Does the actual copying of pixels form the atlas buffer to the
 * image buffer.
 * 
 * Skips any non-printable characters.
 * 
 * @param image The image to draw on.
 * @param texture The font_atlas.
 * @param texoffset The character texture X offset.
 * @param imgoffset The image X offset.
 */
static void ft_mlx_draw_char(t_fdf *data, int32_t texoffset, int32_t imgoffset, int32_t x_ofset, int32_t yy)
{
	if (texoffset < 0)
		return;

	char* pixelx;
	uint8_t* pixeli;
	for (uint32_t y = 0; y < FONT_HEIGHT; y++)
	{
		pixelx = &font_atlas.pixels[(y * font_atlas.width + texoffset) * BPP];
		pixeli = data->image->pixels + ((y * data->image->width + imgoffset) * BPP);
		// memcpy(pixeli, pixelx, FONT_WIDTH * BPP);
		for (uint32_t x = 0; x < FONT_WIDTH; x++)
		{
			uint32_t pixel_offset = x * BPP;
			uint32_t x_pos = imgoffset + x;
			uint32_t y_pos = y;
			
			// access individual color channels
			uint8_t red = *(pixelx + pixel_offset);
			uint8_t green = *(pixelx + pixel_offset + 1);
			uint8_t blue = *(pixelx + pixel_offset + 2);
			
			uint8_t alpha = *(pixelx + pixel_offset + 3);
			if (alpha != 0)
				mlx_put_pixel(data->image, x_pos + x_ofset, y_pos + yy, ((red << 24) | (green << 16) | (blue << 8) | alpha));
			// printf("%d\n", x_pos);
			// mlx_put_pixel(data->image, x_pos + 100, y_pos + 100, 0xf9f9f9);
		}
	}
}

//= Public =//

const mlx_texture_t* ft_mlx_get_font(void)
{
    return ((const mlx_texture_t*)&font_atlas);
}

int32_t ft_mlx_get_texoffset(char c)
{
    const bool _isprint = isprint(c);

    // NOTE: Cheesy branchless operation :D
    // +2 To skip line separator in texture
    return (-1 * !_isprint + ((FONT_WIDTH + 2) * (c - 32)) * _isprint);
}

void ft_mlx_put_string(t_fdf *data, const char* str, int x, int y)
{
	// MLX_NONNULL(mlx);
	// MLX_NONNULL(str);

	const size_t len = strlen(str);
	if (len > MLX_MAX_STRING)
	{
		// mlx_error(MLX_STRTOOBIG);
		return ;
	}
	// Draw the text itself
	int32_t imgoffset = 0;
	for (size_t i = 0; i < len; i++, imgoffset += FONT_WIDTH)
		ft_mlx_draw_char(data, ft_mlx_get_texoffset(str[i]), imgoffset, x, y);
}
