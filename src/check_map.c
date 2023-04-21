/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:12:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/04/20 19:29:09 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int	ft_wordcount(char *line, char c)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	if (line[0] == '\0' || line[0] == '\n')
// 		return (0);
// 	if (line[0] != c)
// 			count++;
// 	while (line[i])
// 	{
// 		if (line[i] == c && line[i + 1] != c && line[i + 1] != '\0' && \
// 			line[i + 1] != '\n')
// 		{
// 			count++;
// 		}
// 		i++;
// 	}

// 	return (count);
// }

// int	get_width(char *filename)
// {
// 	int		fd;
// 	int		width;
// 	char	*line;

// 	fd = open(filename, O_RDONLY);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	width = ft_wordcount(line, ' ');
// 	free(line);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		free(line);
// 	}
// 	close(fd);
// 	return (width);
// }

// int	get_height(char *filename)
// {
// 	int		fd;
// 	int		height;
// 	char	*line;

// 	height = 0;
// 	fd = open(filename, O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (line[0] != '\n')
// 			height++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (height);
// }

// void	fill_map(int *map, char *line)
// {
// 	int		i;
// 	char	**nums;

// 	nums = ft_split(line, ' ');
// 	i = 0;
// 	while (nums[i])
// 	{
// 		map[i] = ft_atoi(nums[i]);
// 		free(nums[i]);
// 		i++;
// 	}
// 	free(nums);
// }

// bool	read_map(t_fdf *data, char *filename)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	data->height = get_height(filename);
// 	data->width = get_width(filename);
// 	printf("width = %d\n", data->width);
// 	printf("height = %d\n", data->height);
// 	data->map = ft_calloc(sizeof(int *), data->height);
// 	i = 0;
// 	while (i < data->height)
// 	{
// 		data->map[i] = ft_calloc(sizeof(int), data->width);
// 		i++;
// 	}
// 	fd = open(filename, O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line || line[0] == '\0' || line[0] == '\n')
// 			break ;
// 		fill_map(data->map[i], line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
//     return (true);
// }