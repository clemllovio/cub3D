#include "cub3D.h"

int	type_file_check(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'b' || file[len - 2] != 'u' || file[len - 3] != 'c'\
		|| file[len - 4] != '.')
	{
		ft_dprintf(2, "Error\nMap name must be finished by .cub\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int is_empty_map(char *file, char *line)
{
	int loop;
	int fd;
	
	loop = 0;
	fd = ft_open(file);
	if (fd == ERROR)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (loop == 0)
			{
				ft_dprintf(2, "Error\nDon't put empty map\n");
				return (FAILURE);
			}
			break ;
		}
		if (line)
			free(line);
		loop++;
	}
	close(fd);
	return (SUCCESS);
}

int	ft_open(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), ERROR);
	return (fd);
}