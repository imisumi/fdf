/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/11 15:20:03 by imisumi          ###   ########.fr       */
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
	int		i;
	int		y;
	int		mod;
	t_fdf	*data;

	data = *d;
	mod = 0;
	i = 1;
	y = 149;
	while (i < 20)
	{
		data->menu_button[i].x = 43;
		data->menu_button[i].y = y;
		data->menu_button[i].width = 24;
		data->menu_button[i].height = 15;
		if (i == 10 || i == 11)
			mod = i - 9;
		if (i % 3 == mod)
			y += 40;
		y += 20;
		i++;
	}
	// data->menu_button[16].x = 83;
	// data->menu_button[16].y = 629;
	// data->menu_button[17].y = 649;
	// data->menu_button[18].x = 83;
	// data->menu_button[18].y = 649;
	data->menu_button[17].x = 83;
	data->menu_button[17].y = 689;
	data->menu_button[18].y = 709;
	data->menu_button[19].x = 83;
	data->menu_button[19].y = 709;
}

bool	is_menu_button_clicked(t_fdf *data, int x, int y, int i)
{
	if (x >= data->menu_button[i].x && x <= data->menu_button[i].x + data->menu_button[i].width && y >= data->menu_button[i].y && y <= data->menu_button[i].y + data->menu_button[i].height)
	{
		return (true);
	}
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
		if (x < data->color_picker[0].x || x > data->color_picker[0].x + \
		data->color_picker[0].width || y < data->color_picker[0].y || \
		y > data->color_picker[0].y + data->color_picker[0].height)
		{
			data->color_picker[0].active = false;
		}
		what_collor_is_clicked(&data, x, y, data->button);
		return ;
	}
	if (action == 0)
	{
		if (is_menu_button_clicked(data, x, y, 1) == true)
			data->camera.x = 0;
		if (is_menu_button_clicked(data, x, y, 2) == true)
			data->camera.y = 0;
		if (is_menu_button_clicked(data, x, y, 3) == true)
			data->camera.z = data->width;;
		if (is_menu_button_clicked(data, x, y, 4) == true)
			data->rotation.x = 0;
		if (is_menu_button_clicked(data, x, y, 5) == true)
			data->rotation.y = 0;
		if (is_menu_button_clicked(data, x, y, 6) == true)
			data->rotation.z = 0;
		if (is_menu_button_clicked(data, x, y, 7) == true)
			data->origin.x = (float)(data->width - 1) / 2.00f;
		if (is_menu_button_clicked(data, x, y, 8) == true)
			data->origin.y = (float)(data->height - 1) / 2.00f;
		if (is_menu_button_clicked(data, x, y, 9) == true)
			data->origin.z = 0;
		if (is_menu_button_clicked(data, x, y, 10) == true)
			data->scale = 1000;
		if (is_menu_button_clicked(data, x, y, 11) == true)
			data->flatten = 1.00f;
		if (is_menu_button_clicked(data, x, y, 12) == true)
		{
			data->perspective = true;
			data->parallel = false;
			data->isometric = false;
			printf("Perspective\n");
		}
		if (is_menu_button_clicked(data, x, y, 13) == true)
		{
			data->perspective = false;
			data->parallel = true;
			data->isometric = false;
			printf("Parallel\n");
		}
		if (is_menu_button_clicked(data, x, y, 14) == true)
		{
			data->perspective = false;
			data->parallel = false;
			data->isometric = true;
			printf("Isometric\n");
		}
		// menu color
		if (is_menu_button_clicked(data, x, y, 15) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 0;
		}
		// grid colors
		if (is_menu_button_clicked(data, x, y, 16) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 16;
			data->color_switch = true;
			// set_grid_colors(data, )
		}
		if (is_menu_button_clicked(data, x, y, 17) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 17;
			data->color_switch = true;
			
		}
		// background colors
		if (is_menu_button_clicked(data, x, y, 18) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 18;
			
		}
		if (is_menu_button_clicked(data, x, y, 19) == true)
		{
			init_color_picker(&data, x, y);
			data->color_picker[0].active = true;
			data->button = 19;
			
		}
	}
	
	// color_picker(&data, 300, 300);
	// Perspective mode
	
	
	// printf("%d\n", action);
}

void	draw_menu_color_select(t_fdf *data)
{
	// draw_rect_2(data, data->menu_button[14]);
	// draw_rect_outline(data, data->menu_button[14], 2, BLACK);

	draw_rect_2(data, data->menu_button[15]);
	draw_rect_outline(data, data->menu_button[15], 2, BLACK);

	draw_rect_2(data, data->menu_button[16]);
	draw_rect_outline(data, data->menu_button[16], 2, BLACK);

	draw_rect_2(data, data->menu_button[17]);
	draw_rect_outline(data, data->menu_button[17], 2, BLACK);

	draw_rect_2(data, data->menu_button[18]);
	draw_rect_outline(data, data->menu_button[18], 2, BLACK);




	draw_rect_2(data, data->menu_button[19]);
	draw_rect_outline(data, data->menu_button[19], 2, BLACK);


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
	
	// if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(data->mlx);

	if (data->color_switch == true)
		set_grid_colors(&data);
	fill_background(data);
	draw_map(&data);
	
	draw_rect_2(data, data->menu_button[0]);

	draw_menu(&data);

	data->menu_button[14].color = data->menu.color;
	
	draw_menu_color_select(data);

	if (data->color_picker[0].active == true)
		render_color_picker(data);
	return ;
}

void	setup(t_fdf **d)
{
	t_fdf	*data;
	int	i;

	i = 0;
	data = *d;
	data->transformed_map = ft_calloc(sizeof(t_vec3 *), data->height + 1);
	data->projected_points = ft_calloc(sizeof(t_vec2 *), data->height + 1);
	while (i < data->height)
	{
		data->transformed_map[i] = ft_calloc(sizeof(t_vec3), data->width + 1);
		data->projected_points[i] = ft_calloc(sizeof(t_vec2), data->width + 1);
		i++;
	}
}

int32_t	main(int32_t argc, char *argv[])
{
	t_fdf	*data;

	data = ft_calloc(sizeof(t_fdf), 1);
	if (read_map(data, argv[1]) == false)
		exit (EXIT_FAILURE);

	setup(&data);

	map_to_vec3(&data);
	set_data_value(&data);

	set_button_pos(&data);
	// set_grid_colors(&data);

	// for (int y = 0; y < data->height; y++)
	// {
	// 	for (int x = 0; x < data->height; x++)
	// 		printf("col = %d\n", data->map_colors[y][x]);
	// }
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
