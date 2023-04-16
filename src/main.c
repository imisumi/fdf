/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/15 16:34:58 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
mlx_image_t	*temp_img;
// float	fov_factor = 640;
// t_vec3	camera_position = {0, 0, -5};

void	vec3_to_vec2(t_fdf **d)
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
			data->projected_point[y][x].x = data->grid[y][x].x;
			data->projected_point[y][x].y = data->grid[y][x].y;
			x++;
		}
		y++;
	}
}

void	cursor_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_fdf	*data;

	data = param;

	// printf("hi\n");
	int32_t	x;
	int32_t	y;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x > 50 && y > 50 && x < 100 & y < 100)
		data->rotation.z = 0;
	printf("%d, %d\n", x, y);
	// printf("%d\n", button);
}

// void	cursor_hook(mouse_key_t key, void *param)
// {
// 	printf("hi\n");

// 	printf("");
// }

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fdf	*data;

	data = param;

	// Rotate X
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->rotation.x += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->rotation.x -= 5.0f;
	// Rotate Y
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->rotation.y += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->rotation.y -= 5.0f;
	// Rotate Z
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->rotation.z += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->rotation.z -= 5.0f;

	
	return ;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->rotation.x += 5;
		// printf("%f\n", data->rotation.x);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->yshift -= 20;
	if (mlx_is_key_down(data->mlx, 81))
		data->angle1 -= 0.1;
	if (mlx_is_key_down(data->mlx, 87))
		data->angle1 += 0.1;
	// vec3_to_vec2(&data);
	// project_points(&data);

	// fill_image(data);
	// draw_cube(&data);
	// draw_map(&data);
	
	// draw_grid(data);
	// draw_point_grid(data);
}

void	ft_loop_hook(void *param)
{
	t_fdf	*data;

	data = param;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// mlx_key_hook(data->mlx, key_hook, data);


	// data->rotation.x += 0.01;
	// data->rotation.y += 0.01;
	// data->rotation.z += 0.01;


	fill_image(data);
	draw_map(&data);
	draw_rect(data, 0, 0, 300, HEIGHT, 0x616161);
	// ft_mlx_put_string(data, "Test", 100, 100);
	draw_menu(&data);
	return ;
	// printf("The string is: %s\n", str);
	
	// return ;
	
	// data->rotation.x += 0.01;
	// data->rotation.y += 0.01;
	// data->rotation.z += 0.01;

	// data->rotation.x = 0;
	// data->rotation.y = 120;
	// data->rotation.z = 0;

	// return ;

	// fill_image(data);
	// draw_cube(&data);
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
	// scale_vec3_map(&data, 50);
	// move_vec3_map(&data, 400, 400);
	printf("%f\n", data->grid[0][0].x);
	// printf("%d\n", data->grid[0][0]);
	data->angle = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->move.z = 0;
	data->rotation.x = 0;
	data->rotation.y = 0;
	data->rotation.z = 0;
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
	// fill_image(data);
	// drawline(data, 100, 100, 400, 500);
	// draw_grid(data);
	// draw_point_grid(data);
	// draw_cube(&data);
	// draw_map(&data);

	fill_image(data);
	draw_map(&data);
	// draw_map1(&data);

	// mlx_key_hook(data->mlx, key_hook, data);
	mlx_key_hook(data->mlx, key_hook, data);
	// mlx_cursor_hook(data->mlx, cursor_hook, data);
	// mlx_mouse_hook(data->mlx, mlx_get_mouse_pos, data);
	// mlx_cursor_hook(data->mlx, cursor_hook, data);
	mlx_mouse_hook(data->mlx, cursor_hook, data);


	mlx_loop_hook(data->mlx, ft_loop_hook, data);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
