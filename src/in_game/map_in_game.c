#include "cub3d.h"

void	map_in_game(t_game *game, char *line, int fd, int len)
{

	game->map = malloc(sizeof(char *) * len);
	line = ft_get_next_line(fd);
	line = skip_empty_line(line, &fd);
	len = 0;
	while (line != NULL && line_is_space(line))
	{
		game->map[len] = ft_strtrim(line, "\n");
		free(line);
	    line = ft_get_next_line(fd);
	    len++;
	}
	game->map[len] = NULL;
}
