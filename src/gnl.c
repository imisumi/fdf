/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:15 by imisumi           #+#    #+#             */
/*   Updated: 2023/01/31 13:41:48 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	printf("BUFFER = %i\n", BUFFER_SIZE);
	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
