/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/20 03:11:48 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	bool		active;
	uint32_t	color;
}	t_rect;

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
	t_vec3	start;
	t_vec3	end;
}	t_line;

typedef struct s_rgb
{
	int	rgba[4];
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_rgb;

typedef struct s_draw
{
	int	z;
	int	z1;
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
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
	int			button;
	int			width;
	int			height;
	int			xshift;
	int			yshift;
	double		angle1;
	double		angle2;
	float		angle;
	int			**map;
	t_vec3		rotation;
	t_vec2		**projected_point;
	t_vec3		**grid;
	t_vec3		camera;
	t_move		move;
	t_vec3		origin;
	float		scale;

	uint32_t	text;

	t_rect		menu;
	t_rect		menu_button[32];
	t_rect		color_picker[17];

	bool		perspective;
	bool		parallel;
	bool		isometric;

	mlx_t		*mlx;
	mlx_image_t	*string;
	mlx_image_t	*g_img;
	mlx_image_t	*image;
}	t_fdf;

#endif