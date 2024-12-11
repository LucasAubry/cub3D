#include "cub3d.h"

void	print_result(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("\n");
	printf("%u\n", game->floor_color.r);
	printf("%u\n", game->floor_color.g);
	printf("%u\n", game->floor_color.b);
	printf("\n");
	printf("%u\n", game->ceiling_color.r);
	printf("%u\n", game->ceiling_color.g);
	printf("%u\n", game->ceiling_color.b);
	printf("\n");
	printf("%p\n", (void *)game->textures.n);
	printf("%p\n", (void *)game->textures.s);
	printf("%p\n", (void *)game->textures.w);
	printf("%p\n", (void *)game->textures.e);
}

void	free_textures(t_textures *textures)
{
    if (textures->n)
        mlx_delete_texture(textures->n);
    if (textures->s)
        mlx_delete_texture(textures->s);
    if (textures->w)
        mlx_delete_texture(textures->w);
    if (textures->e)
        mlx_delete_texture(textures->e);
}

void	free_game(char **map)
{
	int	i;

	i = 0;
    if (map)
    {
        while (map[i])
		{
			free(map[i]);
			i++;
		}
        free(map);
    }
}

void	free_all(t_game *game)
{
    if (!game)
        return ;
    free_textures(&game->textures);
    free_map(game->map);
    if (game->path_file)
        free(game->path_file);
    if (game->mlx)
        mlx_terminate(game->mlx);
    free(game);
}

int	set_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (!game->mlx)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!parsing(game, argv))
		{
			printf("MAIN PARSING");
			return (0);
		}
		print_result(game);
		free_all(game);
	}
}
