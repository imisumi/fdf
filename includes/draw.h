/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/23 16:22:10 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../includes/fdf.h"

// draw.c
void	ft_mlx_put_pixel(t_fdf *data, int x, int y, uint32_t color);
void	draw_rect(t_fdf *data, t_rect rect);
void	draw_rect_outline(t_fdf *d, t_rect rect, int thickness, uint32_t color);

// draw_line.c
t_draw	set_draw_param(t_line line);
void	drawline_2(t_draw *draw, t_line *line);
void	assign_color(t_rgb col[3], int diff[3], int i, int color_steps);
void	calculate_diff(int diff[3], t_rgb col[3]);
void	drawline(t_fdf *data, t_line line, uint32_t start, uint32_t end);

#endif
