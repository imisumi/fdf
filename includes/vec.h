/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/23 16:26:37 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "../includes/fdf.h"

// vector_1.c
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_rotate_x(t_vec3 v, float angle);
t_vec3	vec3_rotate_y(t_vec3 v, float angle);
t_vec3	vec3_rotate_z(t_vec3 v, float angle);

// vector_2.c
void	copy_vec3_2d(t_fdf **d);
void	free_2d_vec2(t_vec2 **map);
void	free_2d_vec3(t_vec3 **map);
void	scale_vec3_map(t_fdf **d, float scale);
void	map_to_vec3(t_fdf **d);

// vector_3.c
void	move_vec3_map(t_fdf **d, float move_x, float move_y);
void	vec3_to_vec2(t_fdf **d);

// Vec_utils.c
void	copy_vec3_2d(t_fdf **d);
void	free_2d_vec2(t_vec2 **map);
void	free_2d_vec3(t_vec3 **map);

#endif
