/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:32 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/05 12:30:17 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_texture(char *line, t_parsing *utils);
static	int	find_asset(char *line, t_parsing *utils);
static	int	store_direction(char *texture, t_parsing *utils);
static int	get_color(char *s, t_parsing *utils);

int	read_to_get_asset(char *path, t_parsing *utils)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		return (ft_dprintf(2, "Error\nThe file couldn't be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (find_asset(line, utils) == FAILURE)
		{
			if (line)
				free(line);
			return (FAILURE);
		}
		if (line)
			free(line);
	}
	if (line)
			free(line);
	if (fd > 2)
		close(fd);
	return (SUCCESS);
}

static	int	find_asset(char *line, t_parsing *utils)
{
	if ((ft_strchr(line, 'W') && ft_strchr(line, 'E')) || \
		(ft_strchr(line, 'N') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'S') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'E') && ft_strchr(line, 'A')))
	{
		if (get_texture(line, utils) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strchr(line, 'C') || ft_strchr(line, 'F'))
	{
		if (get_color(line, utils) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	get_texture(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_asset(texture, s);
	store_direction(texture, utils);
	if (texture)
		free(texture);
	return (SUCCESS);
}

static int	get_color(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_asset(texture, s);
	if (ft_strchr(s, 'C'))
		utils->color_c_path = ft_substr(texture, 1, ft_strlen(texture));
	else if (ft_strchr(s, 'F'))
		utils->color_f_path = ft_substr(texture, 1, ft_strlen(texture));
	if (texture)
		free(texture);
	return (SUCCESS);
}

static	int	store_direction(char *texture, t_parsing *utils)
{
	if (texture && texture[0] == 'N')
		utils->north_path = ft_substr(texture, 2, ft_strlen(texture));
	if (texture && texture[0] == 'S')
		utils->south_path = ft_substr(texture, 2, ft_strlen(texture));
	if (texture && texture[0] == 'E')
		utils->east_path = ft_substr(texture, 2, ft_strlen(texture));
	if (texture && texture[0] == 'W')
		utils->west_path = ft_substr(texture, 2, ft_strlen(texture));
	return (SUCCESS);
}
