/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/30 21:37:39 by ichiro           ###   ########.fr       */
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

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

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

typedef struct s_fdf
{
	int			width;
	int			height;
	int			scale;
	int			xshift;
	int			yshift;
	double		angle1;
	double		angle2;
	int			**map;

	mlx_t		*mlx;
	mlx_image_t	*g_img;
	mlx_image_t	*image;
	t_vec3		points[10];
	t_vec3		c;
}	t_fdf;

// void	draw(float x, float y, float x1, float y1, mlx_image_t *g_img);

void	read_map(t_fdf *data, char *filename);
void	print_map(t_fdf *data);
void	draw_grid(t_fdf *data);
void	drawline(t_fdf *data, int x1, int y1, int x2, int y2);
// void	drawline(t_fdf *data, float x1, float y1, float x2, float y2);
void	rotate(t_vec3 *point, float x, float y, float z);

#endif
