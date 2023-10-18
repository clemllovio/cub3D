/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:34 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/18 15:32:15 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_up(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 5 * sin(data->angle);
	added_value_x = 5 * cos(data->angle);
	map_y = data->py_map - added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) + \
	0.275)][(int)((((map_x) / SQUARE_SIZE) - 0.275))] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) - \
	0.275)][(int)((((map_x) / SQUARE_SIZE) + 0.275))] != '1')
	{
		data->py_map -= added_value_y;
		data->px_map += added_value_x;
	}
}

void	move_down(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 5 * sin(data->angle);
	added_value_x = 5 * cos(data->angle);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map - added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) - \
	0.3)][(int)((((map_x) / SQUARE_SIZE)) - 0.3)] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) + \
	0.3)][(int)((((map_x) / SQUARE_SIZE)) + 0.3)] != '1')
	{
		data->py_map += added_value_y;
		data->px_map -= added_value_x;
	}
}

void	move_left(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 5 * sin(data->angle - M_PI_2);
	added_value_x = 5 * cos(data->angle + M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) - \
	0.3)][(int)(((map_x) / SQUARE_SIZE) + 0.3)] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) + \
	0.3)][(int)(((map_x) / SQUARE_SIZE) - 0.3)] != '1')
	{
		data->py_map += added_value_y;
		data->px_map += added_value_x;
	}
}

void	move_right(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 5 * sin(data->angle + M_PI_2);
	added_value_x = 5 * cos(data->angle - M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(map_y / (SQUARE_SIZE) - \
	0.3)][(int)((map_x / (SQUARE_SIZE)) - 0.3)] != '1' &&
	data->map[(int)((map_y / (SQUARE_SIZE)) + \
	0.3)][(int)(map_x / (SQUARE_SIZE) + 0.3)] != '1')
	{
		data->py_map += added_value_y;
		data->px_map += added_value_x;
	}
}
