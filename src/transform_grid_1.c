/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_grid_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/16 13:22:10 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec2	set_perspective(t_fdf **d, t_vec3 transformed_p, t_vec2 projected_p)
{
	t_fdf	*data;

	data = *d;
	if (data->perspective == true)
		projected_p = perspective_projection(data, transformed_p);
	else if (data->parallel == true)
		projected_p = parallel_projection(data, transformed_p);
	else if (data->isometric == true)
		projected_p = isometric_projection(data, transformed_p);
	return (projected_p);
}

void	transform_2(t_fdf **d)
{
	t_fdf	*data;
	t_vec2	projected_p;
	t_vec3	transformed_p;
	int		xy[2];

	data = *d;
	xy[1] = 0;
	while (xy[1] < data->height)
	{
		xy[0] = 0;
		while (xy[0] < data->width)
		{
			transformed_p = vec3_rotate_x(data->transformed_map[xy[1]][xy[0]], \
				data->rotation.x);
			transformed_p = vec3_rotate_y(transformed_p, data->rotation.y);
			transformed_p = vec3_rotate_z(transformed_p, data->rotation.z);
			transformed_p.z += data->camera.z;
			transformed_p.x += data->camera.x;
			transformed_p.y += data->camera.y;
			projected_p = set_perspective(&data, transformed_p, projected_p);
			data->projected_points[xy[1]][xy[0]] = projected_p;
			xy[0]++;
		}
		xy[1]++;
	}
}

void	transform_1(t_fdf **d)
{
	t_fdf	*data;
	t_vec3	point;
	int		x;
	int		y;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			point = data->transformed_map[y][x];
			point = vec3_sub(point, data->origin);
			point.z *= data->flatten;
			data->transformed_map[y][x] = point;
			x++;
		}
		y++;
	}
}

void	draw_map(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	copy_vec3_2d(&data);
	transform_1(&data);
	transform_2(&data);
	transform_3(&data);
}
