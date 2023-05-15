/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:12:36 by imisumi           #+#    #+#             */
/*   Updated: 2023/05/15 17:29:18 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
