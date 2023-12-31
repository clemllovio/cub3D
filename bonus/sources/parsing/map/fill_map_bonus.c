/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:09:47 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 15:29:26 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	len_of_line(const char *s1);
static char	*copy_line(const char *s1);
static int	copy_map(t_data *data, char *line, int fd, int y);

int	fill_map(char *path, t_data *data, char *line)
{
	int	y;
	int	fd;

	y = 0;
	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	data->map = (char **)ft_calloc(data->size_map + 1, sizeof(char *));
	if (!data->map)
	{
		free_textures(data);
		ft_dprintf(2, "Error\nMalloc failed in fill_map\n");
		return (FAILURE);
	}
	if (copy_map(data, line, fd, y) == FAILURE)
	{
		free_textures(data);
		ft_dprintf(2, "Error\nMalloc failed in fill_map\n");
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

static int	copy_map(t_data *data, char *line, int fd, int y)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (is_map(line) == TRUE && is_empty_line(line) == FALSE)
		{
			data->map[y] = copy_line(line);
			if (!data->map[y])
			{
				secure_free_array(data->map, data->size_map);
				clean_gnl(fd, line);
				return (FAILURE);
			}
			if (line)
				free(line);
			line = get_next_line(fd);
			y++;
		}
		if (line)
			free(line);
	}
	data->map[y] = NULL;
	return (SUCCESS);
}

static int	len_of_line(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		i++;
	}
	return (i);
}

static char	*copy_line(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = len_of_line(s1);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (0);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
