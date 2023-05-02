/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:10:54 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/02 15:13:16 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_rotation(t_fdf *data, mlx_key_data_t key)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->rotation.x += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->rotation.x -= 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->rotation.y += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->rotation.y -= 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->rotation.z += 5.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->rotation.z -= 5.0f;
}

void	set_origin(t_fdf *data, mlx_key_data_t key)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->origin.x += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->origin.x -= 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->origin.y += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->origin.y -= 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->origin.z += 1.0f;
	if (mlx_is_key_down(data->mlx, 61) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->origin.z -= 1.0f;
}

void	perspective_true(t_fdf *d, mlx_key_data_t key)
{
	if (((float)heighest_y(d) * d->flatten) < d->camera.z / 2 && (float)d->width <= d->camera.z && (float)d->height <= d->camera.z)
	{
		set_rotation(d, key);
		if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT) && mlx_is_key_down(d->mlx, MLX_KEY_X))
			d->camera.x += 1.0f;
		if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(d->mlx, MLX_KEY_X))
			d->camera.x -= 1.0f;
		if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT) && mlx_is_key_down(d->mlx, MLX_KEY_Y))
			d->camera.y += 1.0f;
		if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(d->mlx, MLX_KEY_Y))
			d->camera.y -= 1.0f;
		if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(d->mlx, MLX_KEY_Z))
			d->camera.z -= 1.0f;
		if (mlx_is_key_down(d->mlx, 61))
		{
			if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT_SHIFT))
				d->scale += 50.0f;
			else
				d->scale += 10.0f;
		}
		if (mlx_is_key_down(d->mlx, 46))
			d->flatten += 0.10f;
		set_origin(d, key);
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT) && mlx_is_key_down(d->mlx, MLX_KEY_Z))
			d->camera.z += 1.0f;
	if (mlx_is_key_down(d->mlx, MLX_KEY_MINUS) && d->scale > 0)
		{
			if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT_SHIFT))
				d->scale -= 50.0f;
			else
				d->scale -= 10.0f;
		}
	if (mlx_is_key_down(d->mlx, 44))
		d->flatten -= 0.10f;
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fdf	*data;

	data = param;

	printf("%d\n", key);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		exit(EXIT_SUCCESS); 
	}
	if (data->perspective == true)
	{
		perspective_true(data, key);
		return ;
	}
	set_rotation(data, key);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_X))
	// 	data->rotation.x += 5.0f;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_X))
	// 	data->rotation.x -= 5.0f;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
	// 	data->rotation.y += 5.0f;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
	// 	data->rotation.y -= 5.0f;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
	// 	data->rotation.z += 5.0f;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
	// 	data->rotation.z -= 5.0f;
		
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->camera.x += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->camera.x -= 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->camera.y += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->camera.y -= 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->camera.z += 1.0f;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->camera.z -= 1.0f;

	if (mlx_is_key_down(data->mlx, 61))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
			data->scale += 50.0f;
		else
			data->scale += 10.0f;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
			data->scale -= 50.0f;
		else
			data->scale -= 10.0f;
	}
	if (mlx_is_key_down(data->mlx, 44))
		data->flatten -= 0.10f;
	if (mlx_is_key_down(data->mlx, 46))
		data->flatten += 0.10f;
}