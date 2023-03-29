/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/03/29 12:19:38 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>

// float	mod(float i)
// {
// 	return (i < 0) ? -i : i;
// }


// void	draw(float x, float y, float x1, float y1, mlx_image_t *g_img)
// {
// 	float	x_step;
// 	float	y_step;
// 	int		max;

// 	x_step = x1 - x;
// 	y_step = y1 - y;
// 	max = MAX(mod(x_step), mod(y_step));
// 	x_step /= max;
// 	y_step /= max;
// 	while ((int)(x - x1) || (int)(y - y1))
// 	{
// 		mlx_put_pixel(g_img, x, y, 0xffffff);
// 	}
// }
