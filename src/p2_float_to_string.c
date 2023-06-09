/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2_float_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:02:01 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/25 16:03:04 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	input_decimal(char str[64], int i, int num)
{
	while (str[i])
		i++;
	str[i++] = '.';
	if (num == 0 || num == 100)
	{
		str[i] = '0';
		str[i + 1] = '0';
		str[i + 2] = '\0';
		return ;
	}
	str[i] = num / 10 + '0';
	str[i + 1] = num % 10 + '0';
	str[i + 2] = '\0';
}

void	input_int(char str[64], int i, int num)
{
	int		j;
	int		digit;
	char	temp[64];

	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return ;
	}
	j = 0;
	while (num > 0)
	{
		digit = num % 10;
		temp[j] = digit + '0';
		num /= 10;
		j++;
	}
	while (--j >= 0)
	{
		str[i] = temp[j];
		i++;
	}
	str[i] = '\0';
}

void	p2_float_to_string(char str[64], char *string, float f)
{
	int	i;
	int	integer_part;
	int	decima_part;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (f < 0)
			{
				str[i] = '-';
				f *= -1;
				i++;
			}
			integer_part = (int)f;
			decima_part = (int)((f - integer_part) * 100 + 0.5);
			input_int(str, i, integer_part);
			input_decimal(str, i, decima_part);
			str[63] = '\0';
			return ;
		}
		str[i] = string[i];
		i++;
	}
}
