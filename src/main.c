/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/11 22:09:52 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define WIDTH 1080
#define HEIGHT 1080

float	fov_factor = 128;

// t_vec2	project(t_vec3 point)
// {
// 	t_vec2	projected_point = {
// 		.x = (fov_factor * point.x) / point.z,
// 		.y = (fov_factor * point.y) / point.z
// 		};

// 	return (projected_point);
// }

void	project_points(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	int	x = 0;
	int	y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->projected_point[y][x].x = (fov_factor * data->grid[y][x].x) / data->grid[y][x].z;
			data->projected_point[y][x].y = (fov_factor * data->grid[y][x].y) / data->grid[y][x].z;
			// printf("%f, %f, %f\n", fov_factor, data->grid[y][x].x, data->grid[y][x].z);
			// return ;
			x++;
		}
		y++;
	}

}

void	vec3_to_vec2(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	// data->grid
	

	int	x = 0;
	int	y = 0;

	// printf("%d\n", data-)
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->projected_point[y][x].x = data->grid[y][x].x;
			data->projected_point[y][x].y = data->grid[y][x].y;
			// printf("X ");
			// data->projected_point[y][x].x = 100;
			// project(&data->grid[y][x]);
			x++;
		}
		// printf("\n");
		y++;
	}
	// printf("%f\n", vec3->x);
	// printf("%f\n", data->grid[0][0].x);
	// printf("%f\n", data->projected_point[0][0].x);
	
}

void	ft_hook(void *param)
{
	t_fdf	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_1))
	// 	mlx_close_window(mlx);
}

void	rotate_loop(t_fdf **d, float angle)
{
	int	x;
	int y;
	t_fdf	*data;

	// printf("hey\n");
	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->grid[y][x] = vec3_rotate_y(data->grid[y][x], angle);
			data->grid[y][x].z += 5;
			x++;
		}
		y++;
	}
	// data->grid[0][0].y = 300;
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fdf	*data;
	// float		y;

	// data = param;
	data = param;
	// printf("%d\n", key.key);
	// y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->move.x = 0;
		data->move.x += 10;
		// move_vec3_map(&data, data->move.x, 0);
		adjust_vec3(&data, data->move.x, 0);
		// rotate_loop(&data, data->angle);
		// printf("%f\n", data->angle);
		// printf("%f\n", data->grid[0][0].y);
		
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		// data->move.x -= 1;
		// move_vec3_map(&data, data->move.x, 0);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->yshift += 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->yshift -= 20;
	if (mlx_is_key_down(data->mlx, 81))
		data->angle1 -= 0.1;
	if (mlx_is_key_down(data->mlx, 87))
		data->angle1 += 0.1;
	// ft_memset(data->image->pixels, 0, sizeof(int) \
	// 	* data->image->width * data->image->height);
	// vec3_to_vec2(&data);
	project_points(&data);

	fill_image(data);
	// draw_grid(data);
	draw_point_grid(data);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fill_image(t_fdf *data)
{
	int	i;
	int	j;
	int32_t	color;
	int startColor[] = {205, 92, 92};
	int endColor[] = {100, 149, 237};
	int diff[3];
	for (int g = 0; g < 3; g++)
		diff[g] = endColor[g] - startColor[g];
	color = ft_pixel(159, 226, 191, 255);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		int currentColor[3];
		for (int g = 0; g < 3; g++)
			currentColor[g] = startColor[g] + (diff[g] * i / HEIGHT);
		// printf("RGB(%d, %d, %d)\n", currentColor[0], currentColor[1], currentColor[2]);
		color = ft_pixel(currentColor[0], currentColor[1], currentColor[2], 255);
		while (j < WIDTH)
		{
			mlx_put_pixel(data->image, j, i, color);
			j++;
		}
		i++;
	}
	// printf("%x\n", ft_pixel(12, 118, 199, 255));
}

int32_t	main(int32_t argc, char *argv[])
{
	t_fdf	*data;

	data = ft_calloc(sizeof(t_fdf), 1);
	read_map(data, argv[1]);
	map_to_vec3(&data);
	scale_vec3_map(&data, 50);
	move_vec3_map(&data, 400, 400);
	printf("%f\n", data->grid[0][0].x);
	// printf("%d\n", data->grid[0][0]);
	data->angle = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->move.z = 0;
	// printf("%f ", data->grid[y][x].x);
	// printf("%f ", data->grid[y][x].y);
	// printf("%f ", data->grid[2][1].z);
	// return 0;
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH * 3, HEIGHT * 3);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0 == -1))
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	fill_image(data);
	// drawline(data, 100, 100, 400, 500);
	// draw_grid(data);
	// draw_point_grid(data);

	
	mlx_key_hook(data->mlx, key_hook, data);
	// mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
