/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:12:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/25 15:48:35 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_map(t_fdf *data, char *line, int i)
{
	int			j;
	char		**nums;
	char		**num_col;

	data->map[i] = ft_calloc(sizeof(int), data->width);
	data->map_colors[i] = ft_calloc(sizeof(uint32_t), data->width);
	nums = ft_split(line, ' ');
	j = 0;
	while (nums[j] && j < data->width)
	{
		num_col = ft_split(nums[j], ',');
		data->map[i][j] = ft_atoi(num_col[0]);
		data->map_colors[i][j] = WHITE;
		if (num_col[1] != NULL)
			data->map_colors[i][j] = hexstr_to_int32(num_col[1]);
		free_double(num_col);
		j++;
	}
	free_double(nums);
}

void	parse_map(t_fdf *data, char *filename, int fd, int width)
{
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (!fd)
		exit (EXIT_FAILURE);
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
			write(STDERR_FILENO, "Invalid map\n", 13);
			exit (EXIT_FAILURE);
		}
		fill_map(data, line, i);
		free(line);
		i++;
	}
	close(fd);
}

bool	read_map(t_fdf *data, char *filename)
{
	int		fd;
	int		width;

	data->height = get_height(filename);
	data->map = ft_calloc(sizeof(int *), data->height);
	data->map_colors = ft_calloc(sizeof(uint32_t *), data->height);
	width = -1;
	fd = 0;
	parse_map(data, filename, fd, width);
	if (data->height > 500 || data->width > 500)
	{
		write(STDERR_FILENO, "Maximum map size is 500 x 500", 29);
		exit(EXIT_FAILURE);
	}
	return (true);
}
