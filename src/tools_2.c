#include "cub3d.h"

void	len_of_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	game->size_y = i;
}
