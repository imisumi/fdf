void drawline(t_fdf *data, int x, int y, int x1, int y1)
{
	int	dx; 
	int	dy; 
	int	p; 
	dx = x1 - x;
	dy = y1 - y;
	if (dx >= dy)
	{
		p = 2 * dy - dx;
		while (x < x1)
		{
			if (p >= 0)
			{
				mlx_put_pixel(data->g_img, x, y, 0xffffff);
				y = y + 1;
				p = p + 2 * dy -2 * dx;
			}
			else
			{
				mlx_put_pixel(data->g_img, x, y, 0xffffff);
				p = p + 2 * dy;
			}
			x = x + 1;
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (y < y1)
		{
			if (p >= 0)
			{
				mlx_put_pixel(data->g_img, x, y, 0xffffff);
				x = x + 1;
				p = p + 2 * dx -2 * dy;
			}
			else
			{
				mlx_put_pixel(data->g_img, x, y, 0xffffff);
				p = p + 2 * dx;
			}
			y = y + 1;
		}
	}
}