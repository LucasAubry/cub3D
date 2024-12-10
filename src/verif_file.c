#include "cub3d.h"

int	len_of_file(int fd)
{
	int		len;
	char	*line;

	len = 1;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		line = ft_get_next_line(fd);
		len++;
	}
	return (len);
}

void	texture_to_NULL(char **texture, char **fc)
{
	texture[0] = NULL;
	texture[1] = NULL;
	texture[2] = NULL;
	texture[3] = NULL;
	fc[0] = NULL;
	fc[1] = NULL;
}

int	is_space111(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
				&& line[i] != '\n' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	file_order(t_game *game, int fd)
{
	char	*line;
	char	*texture[4];
	char	*fc[2];
	int		len;


	texture_to_NULL(texture, fc);
	len = len_of_file(fd);
	close(fd);
	fd = open(game->path_file, O_RDONLY);

	line = file_to_tab(fd, texture, fc);
	if (!is_space111(line))
		return (0);
	if (!texture_in_game(game, texture))
		return (0);
	if (!fc_in_game(game, fc))
		return (0);
	if (!map_in_game(game, line, fd, len))
		return (0);
	return (1);
}
