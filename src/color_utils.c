/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:51:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 16:44:21 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/font.h"

int	dif_num(int one, int two)
{
	int	i;

	i = 0;
	while (one < two)
	{
		one++;
		i++;
	}
	return (i);
}
