#include "cub3D.h"


void    mini_map(t_data *data, t_draw *draw)
{
	int	x;
	int	y;
	int	x_square;
	int	y_square;
	// int	len_max;

	y = 0;
	y_square = 0;
	// len_max = find_len_max(data->len_line, data->size_map);
	draw_direction_vector(data, draw);
	while (data->map[y])
	{
		x = 0;
		x_square = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				draw_square(draw, x_square / 4, y_square / 4, H_PINK, SQUARE_SIZE / 4);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
				draw_square(draw, x_square / 4, y_square / 4, H_GREY, SQUARE_SIZE / 4);
			x++;
			x_square += SQUARE_SIZE;
		}
		y++;
		y_square += SQUARE_SIZE;
	}
	draw_square(draw, ((data->px_map - ((SQUARE_SIZE / 2)) + 10) / 4) , ((data->py_map - ((SQUARE_SIZE / 2)) +10 ) / 4) , H_PURPLE, ((SQUARE_SIZE / 2)) / 4);
}

int	find_len_max(int *len_line, int size_map)
{
	int	i;
	int	len_max;

	i = 0;
	len_max = 0;
	while (i < size_map)
	{
		if (i == 0)
		 	len_max = len_line[i];
		else if (len_line[i] > len_max)
		 	len_max = len_line[i];
		i++;
	}
	return (len_max);
}