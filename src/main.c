/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/24 16:41:46 by imisumi          ###   ########.fr       */
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


// draw_rect(data, 23, 539, 24, 15, -13421569);
void	set_button_pos(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	// temp menu color
	data->menu_button[0].x = 0;
	data->menu_button[0].y = 0;
	data->menu_button[0].width = 270;
	data->menu_button[0].height = HEIGHT;





	
	data->menu_button[10].x = 43;
	data->menu_button[10].y = 449;
	data->menu_button[10].width = 24;
	data->menu_button[10].height = 15;
	
	data->menu_button[11].x = 43;
	data->menu_button[11].y = 509;
	data->menu_button[11].width = 24;
	data->menu_button[11].height = 15;

	data->menu_button[12].x = 43;
	data->menu_button[12].y = 529;
	data->menu_button[12].width = 24;
	data->menu_button[12].height = 15;

	data->menu_button[13].x = 43;
	data->menu_button[13].y = 549;
	data->menu_button[13].width = 24;
	data->menu_button[13].height = 15;

	// menu color picker
	data->menu_button[14].x = 43;
	data->menu_button[14].y = 609;
	data->menu_button[14].width = 24;
	data->menu_button[14].height = 15;

	data->menu_button[15].x = 43;
	data->menu_button[15].y = 629;
	data->menu_button[15].width = 24;
	data->menu_button[15].height = 15;

	data->menu_button[16].x = 83;
	data->menu_button[16].y = 629;
	data->menu_button[16].width = 24;
	data->menu_button[16].height = 15;

	data->menu_button[17].x = 43;
	data->menu_button[17].y = 649;
	data->menu_button[17].width = 24;
	data->menu_button[17].height = 15;

	data->menu_button[18].x = 83;
	data->menu_button[18].y = 649;
	data->menu_button[18].width = 24;
	data->menu_button[18].height = 15;
}

// bool	is_button_clicked(t_fdf *data, int x, int y, int i)
// {
// 	if (x >= data->menu_button[i].x && \
// 		x <= data->menu_button[i].x + data->menu_button[i].width \
// 		&& y >= data->menu_button[i].y && \
// 		y <= data->menu_button[i].y + data->menu_button[i].height
// 		);
// 		return (true);
// 	return (false);
// }

bool	is_menu_button_clicked(t_fdf *data, int x, int y, int i)
{
	if (x >= data->menu_button[i].x && x <= data->menu_button[i].x + data->menu_button[i].width && y >= data->menu_button[i].y && y <= data->menu_button[i].y + data->menu_button[i].height)
	{
		return (true);
	}
	// printf("hey\n");
	// printf("x = %d, y = %d\n", data->menu_button[i].x, data->menu_button[i].y);
	// printf("x = %d, y = %d\n", data->menu_button[i].x + data->menu_button[i].width, data->menu_button[i].y + data->menu_button[i].height);
	return (false);
}


void	ft_cursor_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_fdf	*data;

	data = param;

	// printf("hi\n");
	int32_t	x;
	int32_t	y;
	// printf
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (action == 0 && data->color_picker[0].active == true)
	{
		if (x < data->color_picker[0].x || x > data->color_picker[0].x + data->color_picker[0].width || y < data->color_picker[0].y || y > data->color_picker[0].y + data->color_picker[0].height)
		{
			data->color_picker[0].active = false;
		}
		what_collor_is_clicked(&data, x, y, data->button);
		return ;
	}
	if (action == 0)
	{
		if (is_menu_button_clicked(data, x, y, 10) == true)
		{
			data->scale = 500;
		}
		if (is_menu_button_clicked(data, x, y, 11) == true)
		{
			data->perspective = true;
			data->parallel = false;
			data->isometric = false;
			printf("Perspective\n");
		}
		if (is_menu_button_clicked(data, x, y, 12) == true)
		{
			data->perspective = false;
			data->parallel = true;
			data->isometric = false;
			printf("Parallel\n");
		}
		if (is_menu_button_clicked(data, x, y, 13) == true)
		{
			data->perspective = false;
			data->parallel = false;
			data->isometric = true;
			printf("Isometric\n");
		}
		// if (is_menu_button_clicked(data, x, y, 13) == true)
		// {
		// 	data->perspective = false;
		// 	data->parallel = false;
		// 	data->isometric = true;
		// 	printf("Isometric\n");
		// }
		// menu color
		if (is_menu_button_clicked(data, x, y, 14) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 0;
		}
		// grid colors
		if (is_menu_button_clicked(data, x, y, 15) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 15;
			
		}
		if (is_menu_button_clicked(data, x, y, 16) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 16;
			
		}
		// background colors
		if (is_menu_button_clicked(data, x, y, 17) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 17;
			
		}
		if (is_menu_button_clicked(data, x, y, 18) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 18;
			
		}
	}
	
	// color_picker(&data, 300, 300);
	// Perspective mode
	
	
	printf("%d\n", action);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fdf	*data;

	data = param;

	// printf("%d\n", key);

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
		
	// Camera x
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->camera.x += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->camera.x -= 1.0f;
	// Rotate Y
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->camera.y += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->camera.y -= 1.0f;
	// Rotate Z
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->camera.z += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->camera.z -= 1.0f;

	// Scale
	if (mlx_is_key_down(data->mlx, 61))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
			data->scale += 50.0f;
		else
			data->scale += 10.0f;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
			data->scale -= 50.0f;
		else
			data->scale -= 10.0f;
	}

	// origin
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->origin.x += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->origin.x -= 1.0f;
	// Rotate Y
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->origin.y += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->origin.y -= 1.0f;
	// Rotate Z
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->origin.z += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->origin.z -= 1.0f;





	// color_picker(&data, 300, 300);
	return ;
}

void	draw_menu_color_select(t_fdf *data)
{
	draw_rect_2(data, data->menu_button[14]);
	draw_rect_outline(data, data->menu_button[14], 2, BLACK);

	draw_rect_2(data, data->menu_button[15]);
	draw_rect_outline(data, data->menu_button[15], 2, BLACK);

	draw_rect_2(data, data->menu_button[16]);
	draw_rect_outline(data, data->menu_button[16], 2, BLACK);

	draw_rect_2(data, data->menu_button[17]);
	draw_rect_outline(data, data->menu_button[17], 2, BLACK);

	draw_rect_2(data, data->menu_button[18]);
	draw_rect_outline(data, data->menu_button[18], 2, BLACK);


	// temp
	// draw_rect_outline(data, data->menu_button[1], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[2], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[3], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[4], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[5], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[6], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[7], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[8], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[9], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[10], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[11], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[12], 2, BLACK);
	// draw_rect_outline(data, data->menu_button[13], 2, BLACK);
}

void	ft_loop_hook(void *param)
{
	t_fdf	*data;

	data = param;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);



	fill_background(data);
	draw_map(&data);
	
	draw_rect_2(data, data->menu_button[0]);

	draw_menu(&data);

	data->menu_button[13].color = data->menu.color;
	
	draw_menu_color_select(data);

	if (data->color_picker[0].active == true)
		render_color_picker(data);
	return ;
}

int32_t	main(int32_t argc, char *argv[])
{
	t_fdf	*data;

	data = ft_calloc(sizeof(t_fdf), 1);
	if (read_map(data, argv[1]) == false)
	{
		exit (EXIT_FAILURE);
	}
	// system("leaks fdf");
	// exit(EXIT_SUCCESS);
	map_to_vec3(&data);
	set_data_value(&data);

	set_button_pos(&data);

	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
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
	
	// t_line line;
	// line.x1 = 50;
	// line.y1 = 50;
	// line.x2 = 800;
	// line.y2 = 500;
	// drawline(data, line, 1, 1);

	mlx_key_hook(data->mlx, key_hook, data);
	mlx_mouse_hook(data->mlx, ft_cursor_hook, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);

	mlx_loop(data->mlx);
	system("leaks fdf");
	mlx_terminate(data->mlx);
	printf("end");
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
