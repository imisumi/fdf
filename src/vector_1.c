/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:45 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/22 14:57:28 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3	vec3_rotate_x(t_vec3 v, float angle)
{
	t_vec3	rotate_vector;

	angle *= (PI / 180);
	rotate_vector.x = v.x;
	rotate_vector.y = v.y * cos(angle) - v.z * sin(angle);
	rotate_vector.z = v.y * sin(angle) + v.z * cos(angle);
	return (rotate_vector);
}

t_vec3	vec3_rotate_y(t_vec3 v, float angle)
{
	t_vec3	rotate_vector;

	angle *= (PI / 180);
	rotate_vector.x = v.x * cos(angle) - v.z * sin(angle);
	rotate_vector.y = v.y;
	rotate_vector.z = v.x * sin(angle) + v.z * cos(angle);
	return (rotate_vector);
}

t_vec3	vec3_rotate_z(t_vec3 v, float angle)
{
	t_vec3	rotate_vector;

	angle *= (PI / 180);
	rotate_vector.x = v.x * cos(angle) - v.y * sin(angle);
	rotate_vector.y = v.x * sin(angle) + v.y * cos(angle);
	rotate_vector.z = v.z;
	return (rotate_vector);
}
