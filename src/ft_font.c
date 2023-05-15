/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_font.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:01:37 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/05/15 16:28:31 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

// pos[0] = pixel_offset
// pos[1] = x_pos
// pos[2] = y_pos
void	ft_mlx_draw_char(t_fdf *d, int32_t txtof, int32_t imgof, int xy_of[2])
{
	char		*pixelx;
	uint8_t		*pixeli;
	uint32_t	pos[3];
	t_rgb		rgb;
	int			xy[2];

	if (txtof < 0)
		return ;
	xy[1] = 0;
	while (xy[1] < FONT_HEIGHT)
	{
		pixelx = &font_atlas.pixels[(xy[1] * font_atlas.width + txtof) * BPP];
		pixeli = d->image->pixels + ((xy[1] * d->image->width + imgof) * BPP);
		xy[0] = 0;
		while (xy[0] < FONT_WIDTH)
		{
			set_font_pos(pos, imgof, xy);
			set_font_rgb(pos, &rgb, pixelx);
			if (rgb.a > 155)
				mlx_put_pixel(d->image, pos[1] + xy_of[0], pos[2] + xy_of[1], \
					((255 << 24) | (rgb.r << 16) | (rgb.b << 8) | rgb.a));
			xy[0]++;
		}
		xy[1]++;
	}
}

const mlx_texture_t	*ft_mlx_get_font(void)
{
	return ((const mlx_texture_t *)&font_atlas);
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
	int		xy_offset[2];

	xy_offset[0] = x;
	xy_offset[1] = y;
	imgoffset = 0;
	len = ft_strlen(str);
	if (len > MLX_MAX_STRING)
		return ;
	i = 0;
	while (i < len)
	{
		ft_mlx_draw_char(data, ft_mlx_get_texoffset(str[i]), \
			imgoffset, xy_offset);
		i++;
		imgoffset += FONT_WIDTH;
	}
}
