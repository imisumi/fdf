/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/22 16:07:57 by imisumi          ###   ########.fr       */
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

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include <ctype.h>

# define PI 3.14159265
#define WIDTH 1580
#define HEIGHT 1080

// void	draw(float x, float y, float x1, float y1, mlx_image_t *g_img);

bool	read_map(t_fdf *data, char *filename);

// Vector.c
void	move_vec3_map(t_fdf **d, float move_x, float move_y);
void	scale_vec3_map(t_fdf **d, float scale);
void	map_to_vec3(t_fdf **d);
t_vec3	vec3_rotate_x(t_vec3 v, float angle);
t_vec3	vec3_rotate_y(t_vec3 v, float angle);
t_vec3	vec3_rotate_z(t_vec3 v, float angle);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);

// transform_grid_1.c
void	draw_map(t_fdf **d);

// transform_grid_2.c
void	transform_3(t_fdf **d);

// Menu.c


void	set_button_pos(t_fdf **d, int i, int y);

// transform.c
void	move_map(t_fdf **d, float num, char side);


void	what_collor_is_clicked(t_fdf **d, int x, int y, int button);
void	draw_rect_outline(t_fdf *data, t_rect rect, int thickness, uint32_t color);
void	fill_background(t_fdf *data);


t_rgb	hex_to_rgb(int hex);


void	set_grid_colors(t_fdf **d);


void	set_data_value(t_fdf **d);
uint32_t	hexstr_to_int32(char *str);

void	key_hook(mlx_key_data_t key, void *param);
int	heighest_y(t_fdf *data);

// Projection.c
t_vec2	perspective_projection(t_fdf *data, t_vec3 point);
t_vec2	parallel_projection(t_fdf *data, t_vec3 point);
t_vec2	isometric_projection(t_fdf *data, t_vec3 point);


// Vec_utils.c
void	copy_vec3_2d(t_fdf **d);
void	free_2d_vec2(t_vec2 **map);
void	free_2d_vec3(t_vec3 **map);



// read_map.c
void	fill_map(t_fdf *data, char *line, int i);
void	parse_map(t_fdf *data, char *filename, int fd, int width);
bool	read_map(t_fdf *data, char *filename);

// read_map_utils.c
int		get_height(char *filename);
int		ft_wordcount(char *line, char c);
void	free_double(char **str);



// vector_1.c
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3 vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_rotate_x(t_vec3 v, float angle);
t_vec3	vec3_rotate_y(t_vec3 v, float angle);
t_vec3	vec3_rotate_z(t_vec3 v, float angle);


// vector_2.c
void	copy_vec3_2d(t_fdf **d);
void	free_2d_vec2(t_vec2 **map);
void	free_2d_vec3(t_vec3 **map);
void	scale_vec3_map(t_fdf **d, float scale);
void	map_to_vec3(t_fdf **d);

// vector_3.c
void	move_vec3_map(t_fdf **d, float move_x, float move_y);
void	vec3_to_vec2(t_fdf **d);

// p2_float_to_string.c
void	p2_float_to_string(char str[64], char *string, float f);
void	input_int(char str[64], int i, int num);
void	input_decimal(char str[64], int i, int num);


// key_hook.c

// cursor_hook.c
void	ft_cursor_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

// colorpicker.c
uint32_t	current_color(int i);
void		render_color_picker(t_fdf *data);
t_rect		set_rect_value(t_picker p, int x_offset, int y_offset, int first);
void		init_color_picker(t_fdf **d, int x_offset, int y_offset);

// color_picker_2.c
bool	is_color_clicked(t_fdf *data, int x, int y, int i);
void	what_collor_is_clicked_2(t_fdf *data, int x, int y, int button);
void	what_collor_is_clicked(t_fdf **d, int x, int y, int button);

#endif
