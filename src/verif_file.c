#include "cub3d.h"

int	verif_texture_fc(char	**texture, char **fc)
{
	if (ft_strncmp(texture[0], "NO ", 3) == 0 &&
		ft_strncmp(texture[1], "SO ", 3) == 0 &&
		ft_strncmp(texture[2], "WE ", 3) == 0 &&
		ft_strncmp(texture[3], "EA ", 3) == 0 &&
		ft_strncmp(fc[0], "F ", 2) == 0 &&
		ft_strncmp(fc[1], "C ", 2) == 0)
		return (1);
	return (0);
}

char	*file_to_tab(char *line, int fd, char **texture, char **fc)
{
	int	i;

	i = 0;
	while (i != 4)
	{
		if (i != 0)
			line = ft_get_next_line(fd);
		line = skip_empty_line(line, &fd);
		texture[i] = line;
		i++;
	}
	i = 0;
	line = skip_empty_line(line, &fd);
	while (i != 2)
	{
		line = ft_get_next_line(fd);
		line = skip_empty_line(line, &fd);
		fc[i] = line;
		i++;
	}
	return (line);
}

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

int	file_order(t_game *game, int fd)
{
	char	*line;
	char	*texture[4];
	char	*fc[2];
	int		len;


	len = len_of_file(fd);
	close(fd);
	fd = open(game->path_file, O_RDONLY);

	line = ft_get_next_line(fd);
	line = skip_empty_line(line, &fd);
	line = file_to_tab(line, fd, texture, fc);
	if (!verif_texture_fc(texture, fc))
		return (0);
	if (!texture_in_game(game, texture))
		return (0);
	if (!fc_in_game(game, fc))
		return (0);
	map_in_game(game, line, fd, len);
	return (1);
}
