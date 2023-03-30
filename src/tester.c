#include "../includes/fdf.h"

#define WIDTH 1080
#define HEIGHT 1080


void	ft_hook(void *param)
{
	t_fdf	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_1))
	// 	mlx_close_window(mlx);
}

// void	k_hook(mlx_key_data_t k, void *tmp)

// void	move_grid(mlx_key_data key, void *param)
// {
// 	printf("%d\n", key);
// }
// -----------------------------------------------------------------------------
void	loops(t_fdf *data)
{
	printf("z = %f\n", data->points[0].x);
	printf("y = %f\n", data->points[0].y);
	printf("z = %f\n", data->points[0].z);
	for (int i = 0; i < 8; i++)
	{
		data->points[i].x -= data->c.x;
		data->points[i].y -= data->c.y;
		data->points[i].z -= data->c.z;
		rotate(&data->points[i], 0.006, 0.003, 0.012);
		data->points[i].x += data->c.x;
		data->points[i].y += data->c.y;
		data->points[i].z += data->c.z;
		mlx_put_pixel(data->image, data->points[i].x, data->points[i].y, 0xffffff);
	}
	for (int i = 0; i < 8; i++)
		mlx_put_pixel(data->image, data->points[i].x, data->points[i].y, 0xffffff);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fdf	*data;

	data = param;
	printf("%d\n", key.key);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->xshift += 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->xshift -= 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->yshift += 20;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->yshift -= 20;
	if (mlx_is_key_down(data->mlx, 81))
		data->angle1 -= 0.1;
	if (mlx_is_key_down(data->mlx, 87))
		data->angle1 += 0.1;
	if (mlx_is_key_down(data->mlx, 65))
		data->angle2 -= 0.1;
	if (mlx_is_key_down(data->mlx, 83))
		data->angle2 += 0.1;
	ft_memset(data->image->pixels, 0, sizeof(int) \
		* data->image->width * data->image->height);
	draw_grid(data);
}

void	ft_loops(mlx_key_data_t key, void *param)
{
	t_fdf	*data;

	data = param;
	printf("%d\n", key.key);
	if (mlx_is_key_down(data->mlx, 32))
		loops(data);
	ft_memset(data->image->pixels, 0, sizeof(int) \
		* data->image->width * data->image->height);
	loops(data);
}

void draw_cube(t_fdf *data)
{
    t_vec3 vertices[8] = {
        {-1, -1, -1}, {1, -1, -1}, {-1, 1, -1}, {1, 1, -1},
        {-1, -1, 1}, {1, -1, 1}, {-1, 1, 1}, {1, 1, 1}
    };
    int edges[12][2] = {
        {0, 1}, {0, 2}, {0, 4}, {1, 3}, {1, 5}, {2, 3},
        {2, 6}, {3, 7}, {4, 5}, {4, 6}, {5, 7}, {6, 7}
    };
    int i;
    for (i = 0; i < 12; i++) {
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        t_vec3 p1 = vertices[v1];
        t_vec3 p2 = vertices[v2];
        drawline(data, p1.x, p1.y, p2.x, p2.y);
    }
}

int32_t	main(int32_t argc, char *argv[])
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	read_map(data, argv[1]);
	data->scale = 30;
	data->xshift = 450;
	data->yshift = 450;
	data->angle1 = 0.8;
	data->angle2 = 0.8;
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH * 3, HEIGHT * 3);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	// int	add = 300;
	// int	ad = 300;
	// data->points[0].x = (100 + add);
	// data->points[0].y = (100 + add);
	// data->points[0].z = (100 + add);

	// data->points[1].x = (200 + add);
	// data->points[1].y = (100 + add);
	// data->points[1].z = (100 + add);

	// data->points[2].x = (200 + add);
	// data->points[2].y = (200 + add);
	// data->points[2].z = (100 + add);

	// data->points[3].x = (100 + add);
	// data->points[3].y = (200 + add);
	// data->points[3].z = (100 + add);

	// data->points[4].x = (100 + ad);
	// data->points[4].y = (100 + ad);
	// data->points[4].z = (200 + ad);

	// data->points[5].x = (200 + ad);
	// data->points[5].y = (100 + ad);
	// data->points[5].z = (200 + ad);

	// data->points[6].x = (200 + ad);
	// data->points[6].y = (200 + ad);
	// data->points[6].z = (200 + ad);

	// data->points[7].x = (100 + ad);
	// data->points[7].y = (200 + ad);
	// data->points[7].z = (200 + ad);


	// data->c.x = 0;
	// data->c.y = 0;
	// data->c.z = 0;

	// for (int i = 0; i < 8; i++)
	// {
	// 	data->c.x += data->points[i].x;
	// 	data->c.y += data->points[i].y;
	// 	data->c.z += data->points[i].z;
	// }
	// data->c.x /= 8;
	// data->c.y /= 8;
	// data->c.z /= 8;

	draw_grid(data);
	draw_cube(data);
	// mlx_put_pixel(data->image, 100, 1.5, 0xffffff);
	// mlx_loop_hook(data->mlx, move_grid, data->mlx);
	mlx_key_hook(data->mlx, key_hook, data);
	// mlx_key_hook(data->mlx, ft_loops, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
