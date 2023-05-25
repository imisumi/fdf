/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:03 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/25 16:03:40 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	setup(t_fdf **d, int i)
{
	t_fdf	*data;

	data = *d;
	data->transformed_map = ft_calloc(sizeof(t_vec3 *), data->height + 1);
	data->projected_points = ft_calloc(sizeof(t_vec2 *), data->height + 1);
	data->grid = ft_calloc(sizeof(t_vec3 *), data->height + 1);
	data->projected_point = ft_calloc(sizeof(t_vec2 *), data->height + 1);
	if (!data->projected_points || !data->transformed_map || \
		!data->grid || !data->projected_point)
		exit(EXIT_FAILURE);
	while (i < data->height)
	{
		data->transformed_map[i] = ft_calloc(sizeof(t_vec3), data->width + 1);
		data->projected_points[i] = ft_calloc(sizeof(t_vec2), data->width + 1);
		data->grid[i] = ft_calloc(sizeof(t_vec3), data->width + 1);
		data->projected_point[i] = ft_calloc(sizeof(t_vec2), data->width + 1);
		if (!data->projected_points[i] || !data->transformed_map[i] || \
			!data->grid[i] || !data->projected_point[i])
			exit(EXIT_FAILURE);
		i++;
	}
	map_to_vec3(d);
	set_data_value(d);
	set_button_pos(d, 1, 149);
}

void	check_file_extension(char *filename, char *extension)
{
	int	len;
	int	ext_len;

	if (open(filename, O_RDONLY) < 0)
	{
		write(STDERR_FILENO, "File not found\n", 15);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	while (ext_len != 0)
	{
		if (filename[len - 1] != extension[ext_len - 1])
		{
			write(STDERR_FILENO, "Wrong file extension, expected: ", 32);
			write(STDERR_FILENO, extension, ft_strlen(extension));
			write(STDERR_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		len--;
		ext_len--;
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

	if (argc != 2)
		exit(EXIT_FAILURE);
	check_file_extension(argv[1], ".fdf");
	data = ft_calloc(sizeof(t_fdf), 1);
	if (read_map(data, argv[1]) == false)
		exit (EXIT_FAILURE);
	setup(&data, 0);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	mlx_actions(data);
}
