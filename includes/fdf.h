/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/23 16:33:03 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/includes/libft.h"

# include "struct.h"

# include "font.h"
# include "colors.h"
# include "menu.h"
# include "draw.h"
# include "vec.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include <ctype.h>
# include <stdint.h>

# define PI 3.14159265
# define WIDTH 1580
# define HEIGHT 1080

// transform_grid_1.c
void	draw_map(t_fdf **d);

// transform_grid_2.c
void	transform_3(t_fdf **d);

// transform.c
void	move_map(t_fdf **d, float num, char side);

// set_value.c
void	set_data_value_2(t_fdf *data);
void	set_data_value(t_fdf **d);
void	set_button_pos(t_fdf **d, int i, int y);

// Projection.c
t_vec2	perspective_projection(t_fdf *data, t_vec3 point);
t_vec2	parallel_projection(t_fdf *data, t_vec3 point);
t_vec2	isometric_projection(t_fdf *data, t_vec3 point);

// read_map.c
void	fill_map(t_fdf *data, char *line, int i);
void	parse_map(t_fdf *data, char *filename, int fd, int width);
bool	read_map(t_fdf *data, char *filename);

// read_map_utils.c
int		get_height(char *filename);
int		ft_wordcount(char *line, char c);
void	free_double(char **str);

// p2_float_to_string.c
void	p2_float_to_string(char str[64], char *string, float f);
void	input_int(char str[64], int i, int num);
void	input_decimal(char str[64], int i, int num);

// key_hook.c
void	set_rotation(t_fdf *data, mlx_key_data_t key);
void	set_origin(t_fdf *data, mlx_key_data_t key);
void	set_position(t_fdf *data, mlx_key_data_t key);
void	set_scale(t_fdf *data, mlx_key_data_t key);
void	key_hook(mlx_key_data_t key, void *param);

// cursor_hook.c
void	ft_cursor_hook(mouse_key_t button, action_t action, \
			modifier_key_t mods, void *param);
void	is_cros_clicked(t_fdf *data, int x, int y);
void	is_background_clicked(t_fdf *data, int x, int y);
bool	is_menu_button_clicked(t_fdf *data, int x, int y, int i);

// cursor_hook_2.c
void	is_projection_clicked(t_fdf *data, int x, int y);
void	is_mg_clicked(t_fdf *data, int x, int y);

#endif
