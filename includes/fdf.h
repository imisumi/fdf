/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/21 17:57:15 by imisumi          ###   ########.fr       */
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

void	print_map(t_fdf *data);
void	draw_grid(t_fdf *data);

// void	drawline(t_fdf *data, int x1, int y1, int x2, int y2);
void drawline(t_fdf *data, t_line line);

// void	drawline(t_fdf *data, float x1, float y1, float x2, float y2);
void	fill_image(t_fdf *data);
void	draw_point_grid(t_fdf *data);
void	draw_rect(t_fdf *data, int x, int y, int width, int height, uint32_t color);

// Vector.c
void	move_vec3_map(t_fdf **d, float move_x, float move_y);
void	scale_vec3_map(t_fdf **d, float scale);
void	map_to_vec3(t_fdf **d);
t_vec3	vec3_rotate_x(t_vec3 v, float angle);
t_vec3	vec3_rotate_y(t_vec3 v, float angle);
t_vec3	vec3_rotate_z(t_vec3 v, float angle);
void	adjust_vec3(t_fdf **d, float move_x, float move_y);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);

// 3Dcube.c
void	draw_map(t_fdf **d);
void	draw_map1(t_fdf **d);
void	draw_cube(t_fdf **d);



// font.c
static void ft_mlx_draw_char(t_fdf *data, int32_t texoffset, int32_t imgoffset, int x , int y);
const mlx_texture_t* ft_mlx_get_font(void);
int32_t ft_mlx_get_texoffset(char c);
void	ft_mlx_put_string(t_fdf *data, const char* str, int32_t x, int32_t y);

// Menu.c
// void	draw_menu(t_fdf **d);

// transform.c
void	move_map(t_fdf **d, float num, char side);

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// void	init_color_picker(t_fdf **d, int x_offset, int y_offset);
// void	render_color_picker(t_fdf *data);

// int	is_button_clicked(t_fdf *data, int x, int y, int i);
void	what_collor_is_clicked(t_fdf **d, int x, int y, int button);
void	draw_rect_outline(t_fdf *data, t_rect rect, int thickness, uint32_t color);
uint8_t	*int_32_to_8(uint32_t color);
void	fill_background(t_fdf *data);


// int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
// int32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
// t_rgb	int32_to_rgb(uint32_t pixel_value);
// uint32_t	hex_to_int32(int hex);

t_rgb	hex_to_rgb(int hex);





void	set_data_value(t_fdf **d);
uint32_t	hexstr_to_int32(char *str);

#endif
