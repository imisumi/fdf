/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dcube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/13 18:54:40 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define WIDTH 1080
#define HEIGHT 1080

float	fov_factor = 500;
t_vec3	camera_position = {0, 0, -10};
// float	fov_factor = 640;
// t_vec3	camera_position = {0, 0, -5};

t_vec2	project_cube(t_vec3 point)
{
	t_vec2	projected_point = {
		.x = (fov_factor * point.x) / point.z,
		.y = (fov_factor * point.y) / point.z
		};

	return (projected_point);
}

void	connect_points(t_fdf *data, t_vec2 *point)
{
	// int	m = + (WIDTH / 2);
	for (int i = 0; i < 8; i++) {
		point[i].x += (WIDTH / 2);
		point[i].y += (WIDTH / 2);
	}
	drawline(data, point[0].x, point[0].y, point[1].x, point[1].y);
	drawline(data, point[0].x, point[0].y, point[3].x, point[3].y);
	drawline(data, point[0].x, point[0].y, point[4].x, point[4].y);

	drawline(data, point[6].x, point[6].y, point[2].x, point[2].y);
	drawline(data, point[6].x, point[6].y, point[5].x, point[5].y);
	drawline(data, point[6].x, point[6].y, point[7].x, point[7].y);

	drawline(data, point[1].x, point[1].y, point[2].x, point[2].y);
	drawline(data, point[1].x, point[1].y, point[5].x, point[5].y);

	drawline(data, point[4].x, point[4].y, point[5].x, point[5].y);
	drawline(data, point[4].x, point[4].y, point[7].x, point[7].y);

	drawline(data, point[2].x, point[2].y, point[3].x, point[3].y);
	
	drawline(data, point[3].x, point[3].y, point[7].x, point[7].y);
}



void	draw_cube(t_fdf **d)
{
	t_fdf	*data;
	data = *d;
	t_vec2	projected_points[8];
	t_vec3 cube_points[8] = {
		{ 1,  1,  1},	// vertex 0
		{-1,  1,  1},	// vertex 1
		{-1, -1,  1},	// vertex 2
		{ 1, -1,  1},	// vertex 3
		{ 1,  1, -1},	// vertex 4
		{-1,  1, -1},	// vertex 5
		{-1, -1, -1},	// vertex 6
		{ 1, -1, -1}	// vertex 7
	};
	// update
	printf("update - %f\n", data->rotation.x);
	for (int i = 0; i < 8; i++)
	{
		t_vec3	point = cube_points[i];

		t_vec3	transformed_point = vec3_rotate_x(point, data->rotation.x);
		transformed_point = vec3_rotate_y(transformed_point, data->rotation.y);
		transformed_point = vec3_rotate_z(transformed_point, data->rotation.z);

		transformed_point.z -= camera_position.z;

		t_vec2	projected_point = project_cube(transformed_point);
		projected_points[i] = projected_point;
	}
	// render
	for (int i = 0; i < 8; i++) {
        t_vec2 projected_point = projected_points[i];
        draw_rect(
			data,
            projected_point.x + (WIDTH / 2),
            projected_point.y + (HEIGHT / 2),
            2,
            2,
            0xFFFFFF00
        );
    }
	// draw lines
	connect_points(data, projected_points);
}

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

void	draw_map(t_fdf **d)
{
	t_fdf	*data = *d;
	t_vec3	**transformed_map;

	// printf("width=%d, heigth=%d, points=%d", data->width,  data->height, GRID_POINTS);

	//	copy's the map into a new 2D vec3
	transformed_map = copy_vec3_2d(data);

	//	sets the vec3 as its origin
	t_vec3 translation = {2, 2, 2};

	int	y = 0;
	int	x = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			t_vec3 point = transformed_map[y][x];
			point = vec3_sub(point, translation);
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

			transformed_point.z -= camera_position.z;

			t_vec2	projected_point = project_cube(transformed_point);
			projected_points[y][x] = projected_point;
			x++;
			// break ;
		}
		// break ;
		// printf("\n");
		y++;
	}


	// Draws little squares on each point
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_rect(
				data,
				projected_points[y][x].x + (WIDTH / 2),
				projected_points[y][x].y + (HEIGHT / 2),
				2,
				2,
				0xFFFFFF00
			);
			// printf("%-5.1f ", projected_points[y][x].y);
			x++;
		}
		y++;
	}


	// Connect all points forming a grid
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				drawline(data,
				projected_points[y][x].x + (WIDTH / 2),
				projected_points[y][x].y + (HEIGHT / 2),
				projected_points[y][x + 1].x + (WIDTH / 2),
				projected_points[y][x + 1].y + (HEIGHT / 2)
				);
			}
			if (y < data->height - 1)
			{
				drawline(data,
				projected_points[y][x].x + (HEIGHT / 2),
				projected_points[y][x].y + (HEIGHT / 2),
				projected_points[y + 1][x].x + (HEIGHT / 2),
				projected_points[y + 1][x].y + (HEIGHT / 2)
				);
			}
			x++;
		}
		y++;
	}
}

// backup
// #define GRID_POINTS 12
// void	draw_map(t_fdf **d)
// {
// 	t_fdf	*data;
// 	data = *d;
// 	t_vec2	projected_points[GRID_POINTS];
// 	t_vec3 cube_points[GRID_POINTS] = {
// 		{ 0,  0,  0},	// vertex 0
// 		{ 1,  0,  0},	// vertex 0
// 		{ 2,  0,  0},	// vertex 0
// 		{ 0,  1,  0},	// vertex 0
// 		{ 1,  1,  1},	// vertex 0
// 		{ 2,  1,  0},	// vertex 0
// 		{ 0,  2,  0},	// vertex 0
// 		{ 1,  2,  0},	// vertex 0
// 		{ 2,  2,  0},	// vertex 0
// 		{ 0,  3,  0},	// vertex 0
// 		{ 1,  3,  0},	// vertex 0
// 		{ 2,  3,  0},	// vertex 0
// 	};
// 	//	sets the midel on the grid as origin
// 	// t_vec3 translation = {1, 1, 0};
// 	t_vec3 translation = {1, 1, 1};
// 	for (int i = 0; i < GRID_POINTS; i++)
// 	{	
// 		t_vec3 point = cube_points[i];
// 		point = vec3_sub(point, translation);
// 		cube_points[i] = point;
// 		// printf("%f, %f, %f\n", cube_points[i].x, cube_points[i].y, cube_points[i].z);
// 	}
// 	// aply rotation to matrix
// 	for (int i = 0; i < GRID_POINTS; i++)
// 	{
// 		t_vec3	point = cube_points[i];

// 		t_vec3	transformed_point = vec3_rotate_x(point, data->rotation.x);
// 		transformed_point = vec3_rotate_y(transformed_point, data->rotation.y);
// 		transformed_point = vec3_rotate_z(transformed_point, data->rotation.z);

// 		transformed_point.z -= camera_position.z;

// 		t_vec2	projected_point = project_cube(transformed_point);
// 		projected_points[i] = projected_point;
// 		// printf("%f, %f\n", projected_points[i].x, projected_points[i].y);
// 	}
// 	for (int i = 0; i < GRID_POINTS; i++)
// 	{
// 		t_vec2 projected_point = projected_points[i];
// 		printf("projected point = %f, %f\n", projected_point.x, projected_point.y);
// 		draw_rect(
// 			data,
// 			projected_point.x + (WIDTH / 2),
// 			projected_point.y + (HEIGHT / 2),
// 			2,
// 			2,
// 			0xFFFFFF00
// 		);
		
// 	}
// }
