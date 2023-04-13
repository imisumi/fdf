/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/13 15:57:07 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/includes/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>

# define PI 3.14159265

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_line
{
    t_vec3 start;
    t_vec3 end;
} t_line;

typedef struct s_rgb
{
	int	rgba[4];
	int	r;
	int	g;
	int	b;
	int	a;
}	t_rgb;

typedef struct s_draw
{
	int	z;
	int	z1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_draw;

typedef struct s_move
{
	float	x;
	float	y;
	float	z;
}	t_move;

typedef struct s_fdf
{
	int			width;
	int			height;
	int			scale;
	int			xshift;
	int			yshift;
	double		angle1;
	double		angle2;
	float		angle;
	int			**map;
	// float		rotation_x;
	// float		rotation_y;
	// float		rotation_z;
	t_vec3		rotation;
	t_vec2		**projected_point;
	t_vec3		**grid;
	t_move		move;

	mlx_t		*mlx;
	mlx_image_t	*g_img;
	mlx_image_t	*image;
}	t_fdf;


// void	draw(float x, float y, float x1, float y1, mlx_image_t *g_img);

void	read_map(t_fdf *data, char *filename);
void	print_map(t_fdf *data);
void	draw_grid(t_fdf *data);
void	drawline(t_fdf *data, int x1, int y1, int x2, int y2);
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
t_vec3 vec3_sub(t_vec3 a, t_vec3 b);
t_vec3 vec3_add(t_vec3 a, t_vec3 b);

// 3Dcube.c
void	draw_map(t_fdf **d);
void	draw_map1(t_fdf **d);
void	draw_cube(t_fdf **d);

#endif
