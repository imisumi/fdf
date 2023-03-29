/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:51:24 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/30 01:45:15 by ichiro           ###   ########.fr       */
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

void	iso(int *x, int *y, int z)
{
	double	angle;

	angle = 0.8;
	*x = (*x - *y) * cos(.8);
	*y = (*x + *y) * sin(.8) - z;
}

void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
{
	int	z;
	int	z1;
	int	mul;

	z = data->map[y1][x1];
	z1 = data->map[y2][x2];

	mul = 30;

	x1 *= mul;
	y1 *= mul;
	x2 *= mul;
	y2 *= mul;

	iso(&x1, &y1, z);
	iso(&x2, &y2, z1);
	x1 += 300;
	y1 += 300;
	x2 += 300;
	y2 += 300;
	
	int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_put_pixel(data->g_img, x1, y1, 0xffffff);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// void drawline(t_fdf *data, int x, int y, int x1, int y1)
// {
// 	int	dx; 
// 	int	dy; 
// 	int	p; 
// 	int	z; 
// 	int	z1;
// 	int	mul;

// 	z = data->map[y][x];
// 	z1 = data->map[y1][x1];

// 	mul = 30;

// 	x *= mul;
// 	y *= mul;
// 	x1 *= mul;
// 	y1 *= mul;

// 	iso(&x, &y, z);
// 	iso(&x1, &y1, z1);
// 	x += 300;
// 	y += 300;
// 	x1 += 300;
// 	y1 += 300;
// 	dx = x1 - x;
// 	dy = y1 - y;
// 	if (dx >= dy)
// 	{
// 		p = 2 * dy - dx;
// 		while (x < x1)
// 		{
// 			if (p >= 0)
// 			{
// 				mlx_put_pixel(data->g_img, x, y, 0xffffff);
// 				y = y + 1;
// 				p = p + 2 * dy -2 * dx;
// 			}
// 			else
// 			{
// 				mlx_put_pixel(data->g_img, x, y, 0xffffff);
// 				p = p + 2 * dy;
// 			}
// 			x = x + 1;
// 		}
// 	}
// 	else
// 	{
// 		p = 2 * dx - dy;
// 		while (y < y1)
// 		{
// 			if (p >= 0)
// 			{
// 				mlx_put_pixel(data->g_img, x, y, 0xffffff);
// 				x = x + 1;
// 				p = p + 2 * dx -2 * dy;
// 			}
// 			else
// 			{
// 				mlx_put_pixel(data->g_img, x, y, 0xffffff);
// 				p = p + 2 * dx;
// 			}
// 			y = y + 1;
// 		}
// 	}
// }

void	draw_grid(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				drawline(data, x, y, (x + 1), y);
			if (y < data->height - 1)
				drawline(data, x, y, x, (y + 1));
			x++;
		}
		y++;
	}
	// mlx_put_pixel(g_img, x, data->height, 0xffffff);
}

void	print_map(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	printf("width = %d\n", data->width);
	printf("height = %d\n", data->height);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));

	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);

	read_map(data, argv[1]);
	print_map(data);
	data->g_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->g_img, 0, 0);

	draw_grid(data);

	// drawline(data->g_img, 10, 10, 100, 15);
	// drawline(data->g_img, 10, 10, 15, 100);
	// drawline(data->g_img, 100, 15, 500, 500);
	// drawline(data->g_img, 15, 100, 500, 500);

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
