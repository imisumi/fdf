/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:51:24 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/29 13:51:42 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


#define WIDTH 1080
#define HEIGHT 1080

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

void drawline(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;
	
	x = x0;
	y = y0;
	if (dx >= dy)
	{
		p = 2 * dy - dx;
		
		while(x < x1)
		{
			if(p >= 0)
			{
				mlx_put_pixel(g_img, x, y, 0xffffff);
				y = y + 1;
				p = p + 2 * dy -2 * dx;
			}
			else
			{
				mlx_put_pixel(g_img, x, y, 0xffffff);
				p = p + 2 * dy;
			}
			x = x + 1;
		}
	}
	else
	{
		p = 2 * dx - dy;
		while(y < y1)
		{
			if(p >= 0)
			{
				mlx_put_pixel(g_img, x, y, 0xffffff);
				x = x + 1;
				p = p + 2 * dx -2 * dy;
			}
			else
			{
				mlx_put_pixel(g_img, x, y, 0xffffff);
				p = p + 2 * dx;
			}
			y = y + 1;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));

	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->g_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->g_img, 0, 0);

	drawline(data->g_img, 10, 10, 100, 15);
	drawline(data->g_img, 10, 10, 15, 100);
	drawline(data->g_img, 100, 15, 500, 500);
	drawline(data->g_img, 15, 100, 500, 500);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}

// int32_t	main(void)
// {
// 	mlx_t	*mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(mlx, g_img, 0, 0);
	
// 	drawline(g_img, 10, 10, 100, 15);
// 	drawline(g_img, 10, 10, 15, 100);
// 	drawline(g_img, 100, 15, 500, 500);
// 	drawline(g_img, 15, 100, 500, 500);

	
// 	mlx_loop(mlx);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }



// int32_t	main(void)
// {
// 	mlx_t	*mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, 1, 1);
// 	ft_memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
// 	mlx_image_to_window(mlx, g_img, 1000, 1000);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_put_pixel(g_img, 100, 100, 0xffffff);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
