/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:45 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/24 15:08:49 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec3 vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return result;
}

t_vec3 vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}


t_vec3 vec3_rotate_x(t_vec3 v, float angle)
{
	angle *= (PI / 180);

	t_vec3	rotate_vector = {
		v.x,
		v.y * cos(angle) - v.z * sin(angle),
		v.y * sin(angle) + v.z * cos(angle)
	};
	return (rotate_vector);
}

t_vec3 vec3_rotate_y(t_vec3 v, float angle)
{
	angle *= (PI / 180);

	// printf("hey\n");
	t_vec3	rotate_vector = {
		v.x * cos(angle) - v.z * sin(angle),
		v.y,
		v.x * sin(angle) + v.z * cos(angle)
	};
	// printf("%f\n", rotate_vector.y);
	return (rotate_vector);
}

// t_vec3 vec3_rotate_z(t_vec3 v, float angle)
// {
// 	t_vec3	rotate_vector = {
// 		v.x * cos(angle) - v.y * sin(angle),
// 		v.x * sin(angle) + v.y * cos(angle),
// 		v.z
// 	};
// 	return (rotate_vector);
// }

t_vec3 vec3_rotate_z(t_vec3 v, float angle)
{
	angle *= (PI / 180);

	t_vec3	rotate_vector = {
		v.x * cos(angle) - v.y * sin(angle),
		v.x * sin(angle) + v.y * cos(angle),
		v.z
	};
	return (rotate_vector);
}

void	adjust_vec3(t_fdf **d, float move_x, float move_y)
{
	t_fdf	*data;
	int		x;
	int		y;
	int		z;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (move_x > 0)
				data->grid[y][x].x += move_x;
			// data->grid[y][x].y += move_y;
			x++;
		}
		y++;
	}
}

void	move_vec3_map(t_fdf **d, float move_x, float move_y)
{
	t_fdf	*data;
	int		x;
	int		y;
	int		z;

	data = *d;
	y = 0;
	// printf("%f\n", move_x);
	// printf("%f\n", move_y);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->grid[y][x].x += move_x;
			data->grid[y][x].y += move_y;
			// printf("%f ", data->grid[y][x].x);
			// printf("%f ", data->grid[y][x].y);
			// printf("%f ", data->grid[y][x].z);
			x++;
		}
		// printf("\n");
		y++;
	}
}

void	scale_vec3_map(t_fdf **d, float scale)
{
	t_fdf	*data;
	int		x;
	int		y;
	int		z;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->grid[y][x].x *= scale;
			data->grid[y][x].y *= scale;
			data->grid[y][x].z *= scale;
			// printf("%f ", data->grid[y][x].x);
			// printf("%f ", data->grid[y][x].y);
			// printf("%f ", data->grid[y][x].z);
			// printf("x ");
			x++;
		}
		// printf("\n");
		y++;
	}
}

void	map_to_vec3(t_fdf **d)
{
	t_fdf	*data;
	int		x;
	int		y;
	int		z;

	data = *d;
	// print_map(data);
	// return ;
	// printf("%d\n", data->width);
	// printf("%d\n", data->height);
	data->grid = ft_calloc(sizeof(t_vec3 *), data->height + 1);
	data->projected_point = ft_calloc(sizeof(t_vec2 *), data->height + 1);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		data->grid[y] = ft_calloc(sizeof(t_vec3), data->width + 1);
		data->projected_point[y] = ft_calloc(sizeof(t_vec2), data->width + 1);
		while (x < data->width)
		{
			z = data->map[y][x];
			data->grid[y][x].x = x;
			data->grid[y][x].y = y;
			data->grid[y][x].z = z;
			// printf("%f %f %f", data->grid[y][x].x, data->grid[y][x].y, data->grid[y][x].z);
			// printf("%f ", data->grid[y][x].y);
			// printf("%d ", z);
			// printf("\t");
			x++;
		}
		// printf("\n");
		y++;
	}
	// exit (0);
}