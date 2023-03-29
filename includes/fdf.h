/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/29 13:48:27 by imisumi          ###   ########.fr       */
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

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**map;

	mlx_t		*mlx;
	mlx_image_t	*g_img;
}	t_fdf;

// void	draw(float x, float y, float x1, float y1, mlx_image_t *g_img);

#endif
