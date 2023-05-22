/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/22 16:07:30 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_menu_color_select(t_fdf *data)
{
	draw_rect(data, data->menu_button[15]);
	draw_rect_outline(data, data->menu_button[15], 2, BLACK);
	draw_rect(data, data->menu_button[16]);
	draw_rect_outline(data, data->menu_button[16], 2, BLACK);
	draw_rect(data, data->menu_button[17]);
	draw_rect_outline(data, data->menu_button[17], 2, BLACK);
	draw_rect(data, data->menu_button[18]);
	draw_rect_outline(data, data->menu_button[18], 2, BLACK);
	draw_rect(data, data->menu_button[19]);
	draw_rect_outline(data, data->menu_button[19], 2, BLACK);
}

void	ft_loop_hook(void *param)
{
	t_fdf	*data;

	data = param;
	if (data->color_switch == true)
		set_grid_colors(&data);
	fill_background(data);
	draw_map(&data);
	draw_rect(data, data->menu_button[0]);
	draw_menu(&data);
	data->menu_button[14].color = data->menu.color;
	draw_menu_color_select(data);
	if (data->color_picker[0].active == true)
		render_color_picker(data);
}

void	setup(t_fdf **d)
{
	t_fdf	*data;
	int		i;

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

void	mlx_actions(t_fdf *data)
{
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_mouse_hook(data->mlx, ft_cursor_hook, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
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
	set_button_pos(&data, 1, 149);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0 == -1))
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	mlx_actions(data);
}
