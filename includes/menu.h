/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/23 16:33:14 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "fdf.h"

// menu_1.c
void	draw_menu(t_fdf **d);
void	menu_position(t_fdf **d, int x_offset, int y_offset);
void	menu_rotation(t_fdf **d, int x_offset, int y_offset);
void	menu_origin(t_fdf **d, int x_offset, int y_offset);
void	menu_scale(t_fdf **d, int x_offset, int y_offset);

// menu_2.c
void	menu_view(t_fdf **d, int x_offset, int y_off);
void	menu_colors(t_fdf **d, int x_offset, int y_offset);
void	menu_flatten(t_fdf **d, int x_offset, int y_offset);
void	draw_menu_color_select(t_fdf *data);

#endif