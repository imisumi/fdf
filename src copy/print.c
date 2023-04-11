#include "../includes/fdf.h"

void	print_map(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	printf("width = %d\n", data->width);
	printf("height = %d\n", data->height);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}