/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/04/15 16:33:48 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu_rotation(t_fdf **d, int x_offset, int y_offset)
{
	t_fdf	*data;

	data = *d;
	ft_mlx_put_string(data, "Rotation", 0 + x_offset, 0 + y_offset);
	char str[64];
	sprintf(str, "X	%.2f", data->rotation.x);
	ft_mlx_put_string(data, str, 0 + x_offset, 20 + y_offset);
	sprintf(str, "Y	%.2f", data->rotation.y);
	ft_mlx_put_string(data, str, 0 + x_offset, 40 + y_offset);
	sprintf(str, "Z	%.2f", data->rotation.z);
	ft_mlx_put_string(data, str, 0 + x_offset, 60 + y_offset);
}

void	draw_menu(t_fdf **d)
{
	t_fdf	*data;

	data = *d;
	menu_rotation(&data, 50, 50);
}