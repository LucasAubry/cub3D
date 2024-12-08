#include "cub3d.h"

char	**path_to_texture(char **texture)
{
	char	*path;
	char	*new_texture;
	int		i;

	i = 0;
	while (i != 4)
	{
		path = ft_strstr(texture[i], "./");
		path = ft_strtrim(path, "\n");
		if (path)
		{
			new_texture = ft_strdup(path);
			free(texture[i]);
			texture[i] = ft_strdup(new_texture);
			free(new_texture);
		}
		i++;
	}
	return (texture);
}

int	texture_in_game(t_game *game, char **texture)
{
	texture = path_to_texture(texture);
    game->textures.n = mlx_load_png(texture[0]);
    game->textures.s = mlx_load_png(texture[1]);
    game->textures.e = mlx_load_png(texture[2]);
    game->textures.w = mlx_load_png(texture[3]);
	if (game->textures.n == NULL || game->textures.s == NULL ||
			game->textures.e == NULL || game->textures.w == NULL)
		return (0);
	return (1);
}
