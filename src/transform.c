/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/22 15:06:04 by imisumi          ###   ########.fr       */
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
				data->grid[y][x].x += num;
			}
			x++;
		}
		y++;
	}
}
