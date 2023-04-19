/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/19 17:14:41 by imisumi          ###   ########.fr       */
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
	data->menu_button[9].x = 43;
	data->menu_button[9].y = 449;
	data->menu_button[9].width = 24;
	data->menu_button[9].height = 15;
	
	data->menu_button[10].x = 43;
	data->menu_button[10].y = 509;
	data->menu_button[10].width = 24;
	data->menu_button[10].height = 15;

	data->menu_button[11].x = 43;
	data->menu_button[11].y = 529;
	data->menu_button[11].width = 24;
	data->menu_button[11].height = 15;

	data->menu_button[12].x = 43;
	data->menu_button[12].y = 549;
	data->menu_button[12].width = 24;
	data->menu_button[12].height = 15;

	data->menu_button[13].x = 43;
	data->menu_button[13].y = 609;
	data->menu_button[13].width = 24;
	data->menu_button[13].height = 15;
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
		what_collor_is_clicked(&data, x, y);
		return ;
	}
	if (action == 0)
	{
		if (is_menu_button_clicked(data, x, y, 9) == true)
		{
			data->scale = 500;
		}
		if (is_menu_button_clicked(data, x, y, 10) == true)
		{
			data->perspective = true;
			data->parallel = false;
			data->isometric = false;
			printf("Perspective\n");
		}
		if (is_menu_button_clicked(data, x, y, 11) == true)
		{
			data->perspective = false;
			data->parallel = true;
			data->isometric = false;
			printf("Parallel\n");
		}
		if (is_menu_button_clicked(data, x, y, 12) == true)
		{
			data->perspective = false;
			data->parallel = false;
			data->isometric = true;
			printf("Isometric\n");
		}
		if (is_menu_button_clicked(data, x, y, 12) == true)
		{
			data->perspective = false;
			data->parallel = false;
			data->isometric = true;
			printf("Isometric\n");
		}
		if (is_menu_button_clicked(data, x, y, 13) == true)
		{
			init_color_picker(&data, x, y);
			// what_collor_is_clicked(&data, x, y);
			data->color_picker[0].active = true;
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

void	ft_loop_hook(void *param)
{
	t_fdf	*data;

	data = param;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);


	fill_image(data);
	// draw_grid(data);
	draw_map(&data);
	// draw_cube(&data);
	// draw_rect(data, 0, 0, 300, HEIGHT, 0x616161);
	draw_rect_2(data, data->menu);

	draw_menu(&data);

	data->menu_button[13].color = data->menu.color;
	draw_rect_2(data, data->menu_button[13]);
	draw_rect_outline(data, data->menu_button[13], 2, BLACK);
	if (data->color_picker[0].active == true)
		render_color_picker(data);
		
	// uint32_t color = ft_pixel(33, 33, 33, 255);
	// if (data->color_picker[13].active == true)
	// 	draw_rect(data, 0, 0, 50, 50, BRIGHT_RED);
	// draw_rect(data, 0, 0, 50, 50, BRIGHT_RED);
	// printf("color = %d\n", color);
	// draw_rect(data, 23, 539, 24, 15, -13421569);

	

	return ;
}



int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// void	fill_image(t_fdf *data)
// {
// 	int	i;
// 	int	j;
// 	int32_t	color;
// 	int startColor[] = {205, 92, 92};
// 	int endColor[] = {100, 149, 237};
// 	int diff[3];
// 	for (int g = 0; g < 3; g++)
// 		diff[g] = endColor[g] - startColor[g];
// 	color = ft_pixel(159, 226, 191, 255);
// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		int currentColor[3];
// 		for (int g = 0; g < 3; g++)
// 			currentColor[g] = startColor[g] + (diff[g] * i / HEIGHT);
// 		// printf("RGB(%d, %d, %d)\n", currentColor[0], currentColor[1], currentColor[2]);
// 		color = ft_pixel(currentColor[0], currentColor[1], currentColor[2], 255);
// 		while (j < WIDTH)
// 		{
// 			ft_mlx_put_pixel(data, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	// printf("%x\n", ft_pixel(12, 118, 199, 255));
// }

// void fill_image(t_fdf *data) {
//     int i, j;
//     uint32_t startColor = ORANGE;
//     uint32_t endColor = ORANGE;
//     uint8_t startColorComponents[4];
//     uint8_t endColorComponents[4];
// 	uint32_t gradient_collor;
//     uint32_t diff[4];

//     startColorComponents[0] = (startColor >> 24); // alpha
//     startColorComponents[1] = (startColor >> 16); // red
//     startColorComponents[2] = (startColor >> 8);  // green
//     startColorComponents[3] = startColor;         // blue

//     endColorComponents[0] = (endColor >> 24); // alpha
//     endColorComponents[1] = (endColor >> 16); // red
//     endColorComponents[2] = (endColor >> 8);  // green
//     endColorComponents[3] = endColor;         // blue


//     // Compute the color difference for each color component
//     for (int g = 0; g < 4; g++) {
//         diff[g] = endColorComponents[g] - startColorComponents[g];
//     }

//     // Iterate over each pixel in the image
//     for (i = 0; i < HEIGHT; i++) {
//         uint8_t currentColorComponents[4];

//         // Compute the current color for this row
//         for (int g = 0; g < 4; g++) {
//             currentColorComponents[g] = startColorComponents[g] + (diff[g] * i / HEIGHT);
//         }

//         // Combine the color components into a single uint32_t color value
//         // uint32_t currentColor = (currentColorComponents[0] << 24) |
//         //                         (currentColorComponents[1] << 16) |
//         //                         (currentColorComponents[2] << 8) |
//         //                         currentColorComponents[3];
// 		gradient_collor = ft_pixel(currentColorComponents[0], currentColorComponents[1], currentColorComponents[2], currentColorComponents[3]);

//         // Fill the row with the current color
//         for (j = 0; j < WIDTH; j++) {
//             ft_mlx_put_pixel(data, j, i, gradient_collor);
//         }
//     }
// }

void fill_image(t_fdf *data) {
    int i, j;
    uint32_t startColor = NAVY_BLUE;
    uint32_t endColor = ORANGE;
    uint8_t startColorComponents[4];
    uint8_t endColorComponents[4];
    uint32_t diff[4];

    // Extract the color components for the start and end colors
    startColorComponents[0] = (startColor >> 24) & 0xFF; // alpha
    startColorComponents[1] = (startColor >> 16) & 0xFF; // red
    startColorComponents[2] = (startColor >> 8) & 0xFF;  // green
    startColorComponents[3] = startColor & 0xFF;         // blue

    endColorComponents[0] = (endColor >> 24) & 0xFF; // alpha
    endColorComponents[1] = (endColor >> 16) & 0xFF; // red
    endColorComponents[2] = (endColor >> 8) & 0xFF;  // green
    endColorComponents[3] = endColor & 0xFF;         // blue

    // Compute the color difference for each color component
    for (int g = 0; g < 4; g++) {
        diff[g] = endColorComponents[g] - startColorComponents[g];
    }

    // Iterate over each pixel in the image
    for (i = 0; i < HEIGHT; i++) {
        uint8_t currentColorComponents[4];

        // Compute the current color for this row
        for (int g = 0; g < 4; g++) {
            currentColorComponents[g] = startColorComponents[g] + (diff[g] * i / HEIGHT);
        }

        // Combine the color components into a single uint32_t color value
        uint32_t currentColor = (currentColorComponents[0] << 24) |
                                (currentColorComponents[1] << 16) |
                                (currentColorComponents[2] << 8) |
                                currentColorComponents[3];

        // Fill the row with the current color
        for (j = 0; j < WIDTH; j++) {
            ft_mlx_put_pixel(data, j, i, currentColor);
        }
    }
}

int32_t	main(int32_t argc, char *argv[])
{
	t_fdf	*data;

	data = ft_calloc(sizeof(t_fdf), 1);
	read_map(data, argv[1]);
	map_to_vec3(&data);
	
	data->menu.x = 0;
	data->menu.y = 0;
	data->menu.width = 270;
	data->menu.height = HEIGHT;
	data->menu.color = OCEAN_BLUE;
	data->text = ORANGE;

	data->angle = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->move.z = 0;
	data->rotation.x = 0;
	data->rotation.y = 0;
	data->rotation.z = 0;
	data->camera.x = 0;
	data->camera.y = 0;
	data->camera.z = 20;
	data->scale = 500.0f;
	data->origin.x = (float)data->width / 2;
	data->origin.y = (float)data->height / 2;
	data->origin.z = 0;

	data->color_picker[0].active = false;

	data->perspective = false;
	data->parallel = false;
	data->isometric = true;
	set_button_pos(&data);

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
	// draw_map(&data);
	// draw_map1(&data);

	// mlx_key_hook(data->mlx, key_hook, data);
	
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_mouse_hook(data->mlx, ft_cursor_hook, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
