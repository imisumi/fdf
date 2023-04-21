/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:12:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/21 18:07:17 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// uint32_t hex2int(char *hex)
// {
// 	uint32_t val;
// 	uint8_t		

// 	val = 0;
// 	while (*hex)
// 	{
// 		// get current character then increment
// 		uint8_t byte = *hex++; 
// 		// transform hex character to the 4bit equivalent number, using the ascii table indexes
// 		if (byte >= '0' && byte <= '9')
// 			byte -= '0';
// 		else if (byte >= 'a' && byte <='f')
// 			byte -= 'a' + 10;
// 		else if (byte >= 'A' && byte <='F')
// 			byte -= 'A' + 10;
// 		// shift 4 to make space for new digit, and add the 4 bits of the new digit 
// 		val = (val << 4) | (byte & 0xF);
// 	}
// 	return val;
// }

void	print_maps(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			printf("%d	", data->map_colors[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int	get_height(char *filename)
{
	int		i;
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line [i] == ' ' || line [i] == '\n')
			i++;
		if (line[i] != '\0')
			height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	ft_wordcount(char *line, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (0);
	if (line[0] != c)
			count++;
	while (line[i])
	{
		if (line[i] == c && line[i + 1] != c && line[i + 1] != '\0' && \
			line[i + 1] != '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	fill_map(t_fdf *data, char *line, int i)
{
	int			j;
	char		**nums;
	char		**num_col;
	uint32_t	colors;
	
	data->map[i] = ft_calloc(sizeof(int), data->width);
	data->map_colors[i] = ft_calloc(sizeof(uint32_t), data->width);
	nums = ft_split(line, ' ');
	j = 0;
	while (nums[j] && j < data->width)
	{
		num_col = ft_split(nums[j], ',');
		printf("%s %s\n", num_col[0], num_col[1]);
		data->map[i][j] = ft_atoi(num_col[0]);
		data->map_colors[i][j] = SKY_BLUE;
		if (num_col[1] != NULL)
			data->map_colors[i][j] = hexstr_to_int32(num_col[1]);
		free_double(num_col);
		free(nums[j]);
		// exit (EXIT_FAILURE);
		// exit(0);
		j++;
	}
	free(nums);
	// exit(0);
}

bool	read_map(t_fdf *data, char *filename)
{
	int		i;
	int		fd;
	int		width;
	char	*line;

	// t_rgb rgb = hex_to_rgb(0xFF0000);
	// printf("%d\n", rgb_to_int32(rgb.r, rgb.g, rgb.b, rgb.a));
	// printf("%d, %d, %d, %d\n", rgb.r, rgb.g, rgb.b, rgb.a);
	// int	hex = hexstr_to_int32("0xFF0000");
	// printf("%d\n", hex);
	// exit (1);
	data->height = get_height(filename);
	data->map = ft_calloc(sizeof(int *), data->height);
	data->map_colors = ft_calloc(sizeof(uint32_t *), data->height);
	fd = open(filename, O_RDONLY);
	if (!fd)
		exit (EXIT_FAILURE);
	width = -1;
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->width = ft_wordcount(line, ' ');
		if (width == -1)
			width = data->width;
		if (width != data->width || data->width == 0)
		{
			printf("Invalid map\n");
			exit (EXIT_FAILURE);
		}
		fill_map(data, line, i);
		printf("hey\n");
		free(line);
		i++;
	}
	// data->height = get_height(filename);
	printf("\nheigth = %d\n", data->height);
	printf("width = %d\n\n\n", data->width);
	print_maps(data);
	return (false);
}
