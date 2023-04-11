/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:51:24 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/11 13:07:42 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


#define WIDTH 1080
#define HEIGHT 1080

mlx_image_t	*g_img;

void	map_to_vec3(t_fdf **data)
{
	print_map(*data);
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
	t_draw	draw;

	draw.z = data->map[y1][x1];
	draw.z1 = data->map[y2][x2];

	x1 *= data->scale;
	y1 *= data->scale;
	x2 *= data->scale;
	y2 *= data->scale;
	iso(&x1, &y1, draw.z);
	iso(&x2, &y2, draw.z1);
	x1 += data->shift;
	y1 += data->shift;
	x2 += data->shift;
	y2 += data->shift;
	draw.dx = abs(x2 - x1);
	draw.dy = abs(y2 - y1);
	draw.sx = (x1 < x2) ? 1 : -1;
	draw.sy = (y1 < y2) ? 1 : -1;
	draw.err = draw.dx - draw.dy;

    while (1) {
        mlx_put_pixel(data->g_img, x1, y1, 0xffffff);
        if (x1 == x2 && y1 == y2) break;
        draw.e2 = 2 * draw.err;
        if (draw.e2 > -draw.dy) {
            draw.err -= draw.dy;
            x1 += draw.sx;
        }
        if (draw.e2 < draw.dx) {
            draw.err += draw.dx;
            y1 += draw.sy;
        }
    }
}

// void drawline(t_fdf *data, int x1, int y1, int x2, int y2)
// {
// 	int	z;
// 	int	z1;

// 	z = data->map[y1][x1];
// 	z1 = data->map[y2][x2];

// 	x1 *= data->scale;
// 	y1 *= data->scale;
// 	x2 *= data->scale;
// 	y2 *= data->scale;
// 	// iso(&x1, &y1, z);
// 	// iso(&x2, &y2, z1);
// 	x1 += 400;
// 	y1 += 400;
// 	x2 += 400;
// 	y2 += 400;
// 	int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         mlx_put_pixel(data->g_img, x1, y1, 0xffffff);
//         if (x1 == x2 && y1 == y2) break;
//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//     }
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

void drawline2(t_fdf *data, float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;
	float	length;
	float	angle;
	float	i;

	dx = x2 - x1;
	dy = y2 - y1;
	length = sqrt(dx * dx + dy * dy);
	angle = atan2(dy, dx);
	i = 0;
	while (i < length)
	{
		mlx_put_pixel(data->g_img, x1 + cos(angle) * i, y1 + sin(angle) * i, 0xffffff);
		i++;
	}
}

int	deal_key(int key, t_fdf *data)
{
	if (key == '+')
		data->shift += 10;
	if (key == '-')
		data->shift -= 10;
	draw_grid(data);
	return (0);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	k_hook(mlx_key_data_t k, void *tmp)
{
	t_fdf	*fdf;

	fdf = (void *)tmp;
	(void) k;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	data = ft_calloc(sizeof(t_fdf), 1);

	// data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// if (!data->mlx)
	// 	exit(EXIT_FAILURE);

	read_map(data, argv[1]);
	map_to_vec3(&data);
	return 0;
	// print_map(data);
	data->g_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->g_img, 0, 0);
	data->scale = 5;
	// data->shift = 30;
	// draw_grid(data);
	// mlx_put_pixel(data->g_img, 100, 100, 0x000000);
	// drawline(data, 100, 110, 300, 110);
	// drawline2(data, 100, 100, 300, 100);
	// drawline2(data, 300, 100, 300, 300);
	// drawline(data, 300, 100, 300, 300);

	// drawline(data, 1, 1, 2, 1);
	// drawline(data, 2, 1, 2, 2);
	// drawline(data, 2, 2, 1, 2);
	// drawline(data, 1, 2, 1, 1);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);

	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
