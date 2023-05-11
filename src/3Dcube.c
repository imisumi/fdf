/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dcube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/11 17:18:23 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	point_to_line_y1(t_fdf **d, int x, int y)
{
	t_fdf	*data;
	t_line	line;

	data = *d;
	line.x1 = data->projected_points[y][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y1 = data->projected_points[y][x].y + (HEIGHT / 2);
	line.x2 = data->projected_points[y + 1][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y2 = data->projected_points[y + 1][x].y + (HEIGHT / 2);
	drawline(data, line, data->map_colors[y][x], data->map_colors[y + 1][x]);
}

void	point_to_line_x1(t_fdf **d, int x, int y)
{
	t_fdf	*data;
	t_line	line;

	data = *d;
	line.x1 = data->projected_points[y][x].x + (WIDTH / 2) + data->menu.width / 2;
	line.y1 = data->projected_points[y][x].y + (HEIGHT / 2);
	line.x2 = data->projected_points[y][x + 1].x + (WIDTH / 2) + data->menu.width / 2;
	line.y2 = data->projected_points[y][x + 1].y + (HEIGHT / 2);
	drawline(data, line, data->map_colors[y][x], data->map_colors[y][x + 1]);
}


void	transform_3(t_fdf **d)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = *d;
	t_line	line;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				point_to_line_x1(&data, x, y);
			if (y < data->height - 1)
				point_to_line_y1(&data, x, y);
			x++;
		}
		y++;
	}
}

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
	int		x;
	int		y;

	y = 0;
	data = *d;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			transformed_p = vec3_rotate_x(data->transformed_map[y][x], data->rotation.x);
			transformed_p = vec3_rotate_y(transformed_p, data->rotation.y);
			transformed_p = vec3_rotate_z(transformed_p, data->rotation.z);
			transformed_p.z += data->camera.z;
			transformed_p.x += data->camera.x;
			transformed_p.y += data->camera.y;
			projected_p = set_perspective(&data, transformed_p, projected_p);
			data->projected_points[y][x] = projected_p;
			x++;
		}
		y++;
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
			// point.z *= .1;
			point.z *= data->flatten;
			data->transformed_map[y][x] = point;
			x++;
		}
		y++;
	}
}

void	draw_map(t_fdf **d)
{
	t_fdf	*data = *d;

	copy_vec3_2d(&data);
	transform_1(&data);
	transform_2(&data);
	transform_3(&data);
}

















#define GRID_POINTS (data->width * data->height)


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