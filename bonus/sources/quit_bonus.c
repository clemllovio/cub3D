/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:43:32 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/18 16:16:21 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	quit_game_error_image(t_data *data)
{
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
#ifdef __linux__

int	quit_game(t_data *data)
{
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	mlx_destroy_image(data->mlx, data->N_texture.img);
	mlx_destroy_image(data->mlx, data->S_texture.img);
	mlx_destroy_image(data->mlx, data->W_texture.img);
	mlx_destroy_image(data->mlx, data->E_texture.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

#elif __APPLE__

int	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	exit(0);
	return (0);
}

#endif