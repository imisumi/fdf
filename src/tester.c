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
	{
		data->angle2 -= 0.1;
		// data->angle2 = PI;
	}
	if (mlx_is_key_down(data->mlx, 83))
	{
		data->angle2 += 0.1;
		// data->angle2 = PI / 2;
	}
	ft_memset(data->image->pixels, 0, sizeof(int) \
		* data->image->width * data->image->height);
	fill_image(data);
	draw_grid(data);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fill_image(t_fdf *data)
{
	int	i;
	int	j;
	int32_t	color;
	int startColor[] = {205, 92, 92};
	int endColor[] = {100, 149, 237};
	int diff[3];
	for (int g = 0; g < 3; g++)
		diff[g] = endColor[g] - startColor[g];
	color = ft_pixel(159, 226, 191, 255);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		int currentColor[3];
		for (int g = 0; g < 3; g++)
			currentColor[g] = startColor[g] + (diff[g] * i / HEIGHT);
		// printf("RGB(%d, %d, %d)\n", currentColor[0], currentColor[1], currentColor[2]);
		color = ft_pixel(currentColor[0], currentColor[1], currentColor[2], 255);
		while (j < WIDTH)
		{
			mlx_put_pixel(data->image, j, i, color);
			j++;
		}
		i++;
	}
	// printf("%x\n", ft_pixel(12, 118, 199, 255));
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
	if (mlx_image_to_window(data->mlx, data->image, 0, 0 == -1))
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	fill_image(data);
	draw_grid(data);

	

	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
