/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:33:59 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/12 17:36:11 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_hook(int key_code, t_data *data);

int mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x > SIZE_X / 2)
		data->right_mouse = 1;
	else if (x < SIZE_X / 2)
		data->left_mouse = 1;
	return (0);
}

void	hook(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 27, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move , data);
	/*mlx_hook(game->screen.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->screen.win, 3, 1L << 1, key_release, game);*/
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

static int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		return (quit_game(data), SUCCESS);
	if (key_code == W_KEY)
		move_up(data);
	if (key_code == A_KEY)
		move_left(data);
	if (key_code == S_KEY)
		move_down(data);
	if (key_code == D_KEY)
		move_right(data);
	if (key_code == LEFT_KEY)
	{
		data->angle += M_PI / 36;
		// if (data->angle < 0)
		// 	data->angle = 2 * M_PI;
	}
	if (key_code == RIGHT_KEY)
	{
		data->angle -= M_PI / 36;
		// if (data->angle > 2 * M_PI)
		// 	data->angle = 0;
	}
	return (SUCCESS);
}
