/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:06:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/15 16:44:24 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "struct.h"

# define BRIGHT_RED		-13421569
# define LIGHT_CORAL	-10066177
# define LAVENDER		-1721316097
# define SKY_BLUE		865717503
# define GOLD			-3407617
# define VANILLA		-13057
# define BLACK			255
# define OCEAN_BLUE		3368703
# define ORANGE			-6736897
# define TURQUOISE		869046783
# define TEAL			862349055
# define NAVY_BLUE		13311
# define SILVER			-858993409
# define GREY			-1717986817
# define DARK_GREY		1717987071
# define CHARCOAL		858993663
# define WHITE			-1

typedef struct s_picker
{
	int	i;
	int	j;
	int	size;
	int	spacing;
	int	x_start;
	int	y_start;
	int	border;
	int	outline;
	
}	t_picker;

void	render_color_picker(t_fdf *data);
void	init_color_picker(t_fdf **d, int x_offset, int y_offset);

// convert_color.c
int32_t		rgb_to_int32(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_rgb		int32_to_rgb(uint32_t pixel_value);
int	hexstr_to_hex(char *str);

// color.c
void		set_grid_colors(t_fdf **d);
void		fill_background(t_fdf *data);
uint32_t	*get_gradient(int steps, uint32_t c1, uint32_t c2);
int			heighest_y(t_fdf *data);
int			*lowest_heighest_y(t_fdf *data);

// color_utils.c
int	dif_num(int one, int two);

#endif
