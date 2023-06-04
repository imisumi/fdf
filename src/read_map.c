/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:12:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/06/04 18:56:54 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	fill_map(t_fdf *data, char *line, int i)
{
	int			j;
	char		**nums;
	char		**num_col;

	data->map[i] = ft_calloc(sizeof(int), data->width);
	data->map_colors[i] = ft_calloc(sizeof(uint32_t), data->width);
	if (!data->map[i] || !data->map_colors[i])
		exit(EXIT_FAILURE);
	nums = ft_split(line, ' ');
	j = 0;
	while (nums[j] && j < data->width)
	{
		num_col = ft_split(nums[j], ',');
		data->map[i][j] = ft_atoi(num_col[0]);
		if (data->map[i][j] > 500)
			exit_msg("Maximum height is 500\n");
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
			exit_msg("Invalid map\n");
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
	if (!data->map || !data->map_colors)
		exit(EXIT_FAILURE);
	width = -1;
	fd = 0;
	parse_map(data, filename, fd, width);
	if (data->height > 500 || data->width > 500)
		exit_msg("Maximum map size is 500 x 500\n");
	return (true);
}
