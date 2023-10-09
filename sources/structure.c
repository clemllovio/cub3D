/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/09 15:08:20 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_data *data, t_parsing *utils)
{
	data->map = NULL;
	data->floor = 0;
	data->celling = 0;
	data->len_line = 0;
	data->size_map = 0;
	data->N = false;
	data->S = false;
	data->E = false;
	data->W = false;
	utils->r = 0;
	utils->g = 0;
	utils->b = 0;
	utils->nb_player = 0;
	utils->north = 0;
	utils->south = 0;
	utils->east = 0;
	utils->west = 0;
	utils->c_color = 0;
	utils->f_color = 0;
	utils->north_path = NULL;
	utils->west_path = NULL;
	utils->east_path = NULL;
	utils->south_path = NULL;
	utils->color_c_path = NULL;
	utils->color_f_path = NULL;
	return ;
}
