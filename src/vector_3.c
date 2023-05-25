/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:45 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/25 15:49:13 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_vec3_map(t_fdf **d, float move_x, float move_y)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->grid[y][x].x += move_x;
			data->grid[y][x].y += move_y;
			x++;
		}
		y++;
	}
}

void	vec3_to_vec2(t_fdf **d)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->projected_point[y][x].x = data->grid[y][x].x;
			data->projected_point[y][x].y = data->grid[y][x].y;
			x++;
		}
		y++;
	}
}
