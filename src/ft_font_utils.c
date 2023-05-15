/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_font_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:01:37 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/05/15 16:26:59 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

void	set_font_pos(uint32_t pos[3], int32_t imgof, int xy[2])
{
	pos[0] = xy[0] * BPP;
	pos[1] = imgof + xy[0];
	pos[2] = xy[1];
}

void	set_font_rgb(uint32_t pos[3], t_rgb *rgb, char *pixelx)
{
	rgb->r = *(pixelx + pos[0]);
	rgb->g = *(pixelx + pos[0] + 1);
	rgb->b = *(pixelx + pos[0] + 2);
	rgb->a = *(pixelx + pos[0] + 3);
}
