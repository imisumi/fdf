/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:32 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 14:09:22 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define GRID_POINTS (data->width * data->height)


void	connect_points(t_fdf *data, t_vec2 *point)
{
	// int	m = + (WIDTH / 2);
	for (int i = 0; i < 8; i++) {
		point[i].x += (WIDTH / 2);
		point[i].y += (HEIGHT / 2);
	}
	draw_line(data, point[0].x, point[0].y, point[1].x, point[1].y);
	draw_line(data, point[0].x, point[0].y, point[3].x, point[3].y);
	draw_line(data, point[0].x, point[0].y, point[4].x, point[4].y);

	draw_line(data, point[6].x, point[6].y, point[2].x, point[2].y);
	draw_line(data, point[6].x, point[6].y, point[5].x, point[5].y);
	draw_line(data, point[6].x, point[6].y, point[7].x, point[7].y);

	draw_line(data, point[1].x, point[1].y, point[2].x, point[2].y);
	draw_line(data, point[1].x, point[1].y, point[5].x, point[5].y);

	draw_line(data, point[4].x, point[4].y, point[5].x, point[5].y);
	draw_line(data, point[4].x, point[4].y, point[7].x, point[7].y);

	draw_line(data, point[2].x, point[2].y, point[3].x, point[3].y);

	draw_line(data, point[3].x, point[3].y, point[7].x, point[7].y);
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
	// printf("update - %f\n", data->rotation.x);
	for (int i = 0; i < 8; i++)
	{
		t_vec3	point = cube_points[i];

		t_vec3	transformed_point = vec3_rotate_x(point, data->rotation.x);
		transformed_point = vec3_rotate_y(transformed_point, data->rotation.y);
		transformed_point = vec3_rotate_z(transformed_point, data->rotation.z);

		transformed_point.z += data->camera.z;

		t_vec2	projected_point = project_cube(data, transformed_point);
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