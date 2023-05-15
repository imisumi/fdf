/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:16:48 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 15:24:01 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_draw	set_draw_param(t_line line)
{
	t_draw	draw;

	draw.delta_x = abs(line.x2 - line.x1);
	draw.delta_y = abs(line.y2 - line.y1);
	if (line.x1 < line.x2)
		draw.sign_x = 1;
	else
		draw.sign_x = -1;
	if (line.y1 < line.y2)
		draw.sign_y = 1;
	else
		draw.sign_y = -1;
	draw.err = draw.delta_x - draw.delta_y;
	return (draw);
}

void	drawline_2(t_draw *draw, t_line *line)
{
	draw->e2 = 2 * draw->err;
	if (draw->e2 > -draw->delta_y)
	{
		draw->err -= draw->delta_y;
		line->x1 += draw->sign_x;
	}
	if (draw->e2 < draw->delta_x)
	{
		draw->err += draw->delta_x;
		line->y1 += draw->sign_y;
	}
}

void	assign_color(t_rgb col[3], int diff[3], int i, int color_steps)
{
	col[2].r = col[0].r + (diff[0] * i / color_steps);
	col[2].g = col[0].g + (diff[1] * i / color_steps);
	col[2].b = col[0].b + (diff[2] * i / color_steps);
}

void	calculate_diff(int diff[3], t_rgb col[3])
{
	diff[0] = col[1].r - col[0].r;
	diff[1] = col[1].g - col[0].g;
	diff[2] = col[1].b - col[0].b;
}

void	drawline(t_fdf *data, t_line line, uint32_t start, uint32_t end)
{
	t_draw	draw;
	int		steps[2];
	int		diff[3];
	t_rgb	col[3];

	draw = set_draw_param(line);
	col[0] = int32_to_rgb(start);
	col[1] = int32_to_rgb(end);
	calculate_diff(diff, col);
	steps[1] = draw.delta_x;
	if (draw.delta_x < draw.delta_y)
		steps[1] = draw.delta_y;
	if (steps[1] < 1)
		steps[1] = 1;
	steps[0] = 0;
	while (true)
	{
		assign_color(col, diff, steps[0], steps[1]);
		ft_mlx_put_pixel(data, line.x1, line.y1, \
			rgb_to_int32(col[2].r, col[2].g, col[2].b, 255));
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		drawline_2(&draw, &line);
		steps[0]++;
	}
}
