/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/17 16:09:01 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_map(t_fdf **d, float num, char side)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = *d;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (side == 'x')
			{
				data->move.x += num;
				data->grid[y][x].x += num;
			}
			x++;
		}
		y++;
	}

	// y = 0;
	// while (y < data->height)
	// {
	// 	x = 0;
	// 	while (x < data->width)
	// 	{
	// 		if (side == 'x')
	// 			data->move.x += num;
	// 		x++;
	// 	}
	// 	y++;
	// }
}