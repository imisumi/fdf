/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dcube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/25 03:57:02 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	fov_factor = 500;

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
	// printf("%f\n", point.z);
	t_vec2	projected_point = {
		.x = (data->scale * point.x) / point.z,
		.y = (data->scale * point.y) / point.z
		};
	return (projected_point);
}

// t_vec2	parallel_projection(t_fdf *data, t_vec3 point)
// {
// 	t_vec2	projected_point = {
// 		.x = (data->scale * point.x) / 20.0f,
// 		.y = (data->scale * point.y) / 20.0f
// 		};
// 	return (projected_point);
// }

// t_vec2	perspective_projection(t_fdf *data, t_vec3 point)
// {
// 	printf("%f\n", point.z);
// 	t_vec2	projected_point = {
// 		.x = point.x / point.z,
// 		.y = point.y / point.z
// 		};
// 	projected_point.x *= data->scale;
// 	projected_point.y *= data->scale;
// 	return (projected_point);
// }

t_vec2	parallel_projection(t_fdf *data, t_vec3 point)
{
	t_vec2	projected_point = {
		.x = point.x / (data->scale / 2),
		.y = point.y / (data->scale / 2)
		};
	projected_point.x *= data->scale;
	projected_point.y *= data->scale;
	return (projected_point);
	// t_vec2	projected_point = {
	// 	.x = point.x,
	// 	.y = point.y
	// 	};
	// projected_point.x *= data->scale;
	// projected_point.y *= data->scale;
	return (projected_point);
}

t_vec2	isometric_projection(t_fdf *data, t_vec3 point)
{
	t_vec2	projected_point = {
		.x = (point.x - point.y) * cos(M_PI / 6),
		.y = (point.x + point.y) * sin(M_PI / 6) - point.z
	};

	projected_point.x *= data->scale / 20;
	projected_point.y *= data->scale / 20;

	projected_point.y += data->scale;
	return (projected_point);
}

// void	connect_points(t_fdf *data, t_vec2 *point)
// {
// 	// int	m = + (WIDTH / 2);
// 	for (int i = 0; i < 8; i++) {
// 		point[i].x += (WIDTH / 2);
// 		point[i].y += (HEIGHT / 2);
// 	}
// 	drawline(data, point[0].x, point[0].y, point[1].x, point[1].y);
// 	drawline(data, point[0].x, point[0].y, point[3].x, point[3].y);
// 	drawline(data, point[0].x, point[0].y, point[4].x, point[4].y);

// 	drawline(data, point[6].x, point[6].y, point[2].x, point[2].y);
// 	drawline(data, point[6].x, point[6].y, point[5].x, point[5].y);
// 	drawline(data, point[6].x, point[6].y, point[7].x, point[7].y);

// 	drawline(data, point[1].x, point[1].y, point[2].x, point[2].y);
// 	drawline(data, point[1].x, point[1].y, point[5].x, point[5].y);

// 	drawline(data, point[4].x, point[4].y, point[5].x, point[5].y);
// 	drawline(data, point[4].x, point[4].y, point[7].x, point[7].y);

// 	drawline(data, point[2].x, point[2].y, point[3].x, point[3].y);
	
// 	drawline(data, point[3].x, point[3].y, point[7].x, point[7].y);
// }



// void	draw_cube(t_fdf **d)
// {
// 	t_fdf	*data;
// 	data = *d;
// 	t_vec2	projected_points[8];
// 	t_vec3 cube_points[8] = {
// 		{ 1,  1,  1},	// vertex 0
// 		{-1,  1,  1},	// vertex 1
// 		{-1, -1,  1},	// vertex 2
// 		{ 1, -1,  1},	// vertex 3
// 		{ 1,  1, -1},	// vertex 4
// 		{-1,  1, -1},	// vertex 5
// 		{-1, -1, -1},	// vertex 6
// 		{ 1, -1, -1}	// vertex 7
// 	};
// 	// update
// 	// printf("update - %f\n", data->rotation.x);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		t_vec3	point = cube_points[i];

// 		t_vec3	transformed_point = vec3_rotate_x(point, data->rotation.x);
// 		transformed_point = vec3_rotate_y(transformed_point, data->rotation.y);
// 		transformed_point = vec3_rotate_z(transformed_point, data->rotation.z);

// 		transformed_point.z += data->camera.z;

// 		t_vec2	projected_point = project_cube(data, transformed_point);
// 		projected_points[i] = projected_point;
// 	}
// 	// render
// 	for (int i = 0; i < 8; i++) {
//         t_vec2 projected_point = projected_points[i];
//         draw_rect(
// 			data,
//             projected_point.x + (WIDTH / 2),
//             projected_point.y + (HEIGHT / 2),
//             2,
//             2,
//             0xFFFFFF00
//         );
//     }
// 	// draw lines
// 	connect_points(data, projected_points);
// }

t_vec3	**copy_vec3_2d(t_fdf *data)
{
	t_vec3	**transformed_map;
	int	x;
	int	y;


	transformed_map = ft_calloc(sizeof(t_vec3 *), data->height + 1);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		transformed_map[y] = ft_calloc(sizeof(t_vec3), data->width + 1);
		while (x < data->width)
		{
			transformed_map[y][x] = data->grid[y][x];
			x++;
		}
		y++;
	}
	return (transformed_map);
}

#define GRID_POINTS (data->width * data->height)

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

void	draw_map(t_fdf **d)
{
	t_fdf	*data = *d;
	t_vec3	**transformed_map;

	// printf("width=%d, heigth=%d, points=%d", data->width,  data->height, GRID_POINTS);

	//	copy's the map into a new 2D vec3
	transformed_map = copy_vec3_2d(data);

	//	sets the vec3 as its origin
	// t_vec3 translation = {WIDTH / 2, HEIGHT / 2, 0};

	int	y = 0;
	int	x = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			t_vec3 point = transformed_map[y][x];
			point = vec3_sub(point, data->origin);
			transformed_map[y][x] = point;
			// printf("%-5.1f ", transformed_map[y][x].y);
			x++;
		}
		// printf("\n");
		y++;
	}

	// return ;
	//	Aply rotation to matrix
	t_vec2	**projected_points;
	projected_points = ft_calloc(sizeof(t_vec2 *), data->height + 1);
	y = 0;
	// printf("%f\n", data->rotation.x);
	while (y < data->height)
	{
		x = 0;
		projected_points[y] = ft_calloc(sizeof(t_vec2), data->width + 1);
		while (x < data->width)
		{
			t_vec3	point = transformed_map[y][x];

			t_vec3	transformed_point = vec3_rotate_x(point, data->rotation.x);
			transformed_point = vec3_rotate_y(transformed_point, data->rotation.y);
			transformed_point = vec3_rotate_z(transformed_point, data->rotation.z);

			transformed_point.z += data->camera.z;

			transformed_point.x += data->camera.x;
			transformed_point.y += data->camera.y;

			t_vec2	projected_point;
			if (data->perspective == true)
				projected_point = perspective_projection(data, transformed_point);
			else if (data->parallel == true)
				projected_point = parallel_projection(data, transformed_point);
			else if (data->isometric == true)
				projected_point = isometric_projection(data, transformed_point);
			projected_points[y][x] = projected_point;
			x++;
		}
		y++;
	}


	// Draws little squares on each point
	// y = 0;
	// while (y < data->height)
	// {
	// 	x = 0;
	// 	while (x < data->width)
	// 	{
	// 		draw_rect(
	// 			data,
	// 			projected_points[y][x].x + (WIDTH / 2),
	// 			projected_points[y][x].y + (HEIGHT / 2),
	// 			2,
	// 			2,
	// 			0xFFFFFF00
	// 		);
	// 		// printf("%-5.1f ", projected_points[y][x].y);
	// 		x++;
	// 	}
	// 	y++;
	// }

	t_line	line;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			line.y1_c = y;
			line.y2_c = y;
			if (x < data->width - 1)
			{
				line.x1 = projected_points[y][x].x + (WIDTH / 2);
				line.y1 = projected_points[y][x].y + (HEIGHT / 2);
				line.x2 = projected_points[y][x + 1].x + (WIDTH / 2);
				line.y2 = projected_points[y][x + 1].y + (HEIGHT / 2);
				drawline(data, line, data->map_colors[y][x], data->map_colors[y][x + 1]);
			}
			if (y < data->height - 1)
			{
				line.x1 = projected_points[y][x].x + (WIDTH / 2);
				line.y1 = projected_points[y][x].y + (HEIGHT / 2);
				line.x2 = projected_points[y + 1][x].x + (WIDTH / 2);
				line.y2 = projected_points[y + 1][x].y + (HEIGHT / 2);
				line.y2_c = y + 1;
				drawline(data, line, data->map_colors[y][x], data->map_colors[y + 1][x]);
			}
			x++;
		}
		y++;
	}



	// t_line	line;
	// y = 0;
	// while (y < data->height)
	// {
	// 	x = 0;
	// 	while (x < data->width)
	// 	{
	// 		line.y1_c = y;
	// 		line.y2_c = y;
	// 		if (x < data->width - 1)
	// 		{
	// 			line.x1 = projected_points[y][x].x + (WIDTH / 2);
	// 			line.y1 = projected_points[y][x].y + (HEIGHT / 2);
	// 			line.x2 = projected_points[y][x + 1].x + (WIDTH / 2);
	// 			line.y2 = projected_points[y][x + 1].y + (HEIGHT / 2);
	// 			draw_line(data, line);
	// 		}
	// 		if (y < data->height - 1)
	// 		{
	// 			line.x1 = projected_points[y][x].x + (WIDTH / 2);
	// 			line.y1 = projected_points[y][x].y + (HEIGHT / 2);
	// 			line.x2 = projected_points[y + 1][x].x + (WIDTH / 2);
	// 			line.y2 = projected_points[y + 1][x].y + (HEIGHT / 2);
	// 			line.y2_c = y + 1;
	// 			draw_line(data, line);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	free_2d_vec2(projected_points);
	free_2d_vec3(transformed_map);
}
