/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/22 15:57:47 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

void	draw_rect(t_fdf *data, t_rect rect)
{
	int	i;
	int	j;
	int	cx;
	int	cy;

	i = 0;
	while (i < rect.width)
	{
		j = 0;
		while (j < rect.height)
		{
			cx = rect.x + i;
			cy = rect.y + j;
			ft_mlx_put_pixel(data, cx, cy, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_rect_outline(t_fdf *d, t_rect rect, int thickness, uint32_t color)
{
	int	i;
	int	j;
	int	cx;
	int	cy;

	i = 0;
	while (i < rect.width)
	{
		j = 0;
		while (j < rect.height)
		{
			cx = rect.x + i;
			cy = rect.y + j;
			if (cx < rect.x + thickness)
				ft_mlx_put_pixel(d, cx, cy, color);
			if (cx >= rect.x + rect.width - thickness)
				ft_mlx_put_pixel(d, cx, cy, color);
			if (cy < rect.y + thickness)
				ft_mlx_put_pixel(d, cx, cy, color);
			if (cy >= rect.y + rect.height - thickness)
				ft_mlx_put_pixel(d, cx, cy, color);
			j++;
		}
		i++;
	}
}
