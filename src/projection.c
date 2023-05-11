/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:38:21 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/11 15:38:39 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec2	project_cube(t_fdf *data, t_vec3 point)
{
	t_vec2	projected_point = {
		.x = (data->scale * point.x) / point.z,
		.y = (data->scale * point.y) / point.z
		};

	return (projected_point);
}

t_vec2	perspective_projection(t_fdf *data, t_vec3 point)
{
	t_vec2	projected_point = {
		.x = (data->scale * point.x) / point.z,
		.y = (data->scale * point.y) / point.z
		};
	return (projected_point);
}


t_vec2	parallel_projection(t_fdf *data, t_vec3 point)
{
	// t_vec2	projected_point = {
	// 	.x = point.x / (data->scale / 2),
	// 	.y = point.y / (data->scale / 2)
	// 	};
	t_vec2	projected_point = {
		.x = point.x / data->camera.z,
		.y = point.y / data->camera.z
		};
	projected_point.x *= data->scale;
	projected_point.y *= data->scale;
	// printf("%f\n", point.z);
	return (projected_point);
}

t_vec2	isometric_projection(t_fdf *data, t_vec3 point)
{
	float	i;
	float	j;
	
	t_vec2	projected_point = {
		.x = (point.x - point.y) * cos(M_PI / 6),
		.y = (point.x + point.y) * sin(M_PI / 6) - point.z
	};
	if (data->height > data->width)
		i = data->height;
	else
		i = data->width;
	j = (data->scale / 2) - i;
	i = (data->scale / 2) / i;
	projected_point.x *= i;
	projected_point.y *= i;

	
	projected_point.y += data->camera.z + j;
	return (projected_point);
}