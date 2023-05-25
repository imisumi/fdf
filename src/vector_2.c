/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/25 15:48:59 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	copy_vec3_2d(t_fdf **d)
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
			data->transformed_map[y][x] = data->grid[y][x];
			x++;
		}
		y++;
	}
}

void	free_2d_vec2(t_vec2 **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_2d_vec3(t_vec3 **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	scale_vec3_map(t_fdf **d, float scale)
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
			data->grid[y][x].x *= scale;
			data->grid[y][x].y *= scale;
			data->grid[y][x].z *= scale;
			x++;
		}
		y++;
	}
}

// void	map_to_vec3(t_fdf **d)
// {
// 	t_fdf	*data;
// 	int		x;
// 	int		y;
// 	int		z;

// 	data = *d;
// 	data->grid = ft_calloc(sizeof(t_vec3 *), data->height + 1);
// 	data->projected_point = ft_calloc(sizeof(t_vec2 *), data->height + 1);
// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		data->grid[y] = ft_calloc(sizeof(t_vec3), data->width + 1);
// 		data->projected_point[y] = ft_calloc(sizeof(t_vec2), data->width + 1);
// 		while (x < data->width)
// 		{
// 			z = data->map[y][x];
// 			data->grid[y][x].x = x;
// 			data->grid[y][x].y = y;
// 			data->grid[y][x].z = z;
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	map_to_vec3(t_fdf **d)
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
			z = data->map[y][x];
			data->grid[y][x].x = x;
			data->grid[y][x].y = y;
			data->grid[y][x].z = z;
			x++;
		}
		y++;
	}
}
