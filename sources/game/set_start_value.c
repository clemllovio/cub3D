/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:08 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/12 10:54:39 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_start_direction(t_data *data);
static int	init_texture(t_draw *texture, char *texture_path, void *mlx);

int	set_start_value(t_data *data)
{
	data->px_map = (data->x_pers * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	data->py_map = (data->y_pers * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	if (init_texture(&data->N_texture, data->north_path, data->mlx) == FAILURE)
		return (FAILURE);
	if (init_texture(&data->S_texture, data->south_path, data->mlx) == FAILURE)
		return (FAILURE);
	if (init_texture(&data->W_texture, data->west_path, data->mlx) == FAILURE)
		return (FAILURE);
	if (init_texture(&data->E_texture, data->east_path, data->mlx) == FAILURE)
		return (FAILURE);
	set_start_direction(data);
	return (SUCCESS);
}

static void	set_start_direction(t_data *data)
{
	if (data->N == true)
		data->N = false;
	else if (data->S == true)
	{
		data->S = false;
		data->angle += (M_PI * 180) / 180;
	}
	else if (data->W == true)
	{
		data->W = false;
		data->angle += M_PI_2;
	}
	else if (data->E == true)
	{
		data->E = false;
		data->angle -= M_PI_2;
	}
}

#include <stdio.h>

static int	init_texture(t_draw *texture, char *texture_path, void *mlx)
{
	int	size;
	
	size = SIZE_IMG;
	texture->img = mlx_xpm_file_to_image(mlx, texture_path, &size, &size);
	if (!(texture->img))
		return (FAILURE);
	// printf("\n\n%d %d\n\n", texture->width, texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!(texture->addr))
		return (FAILURE);
	return (SUCCESS);
}