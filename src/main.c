#include "cub3d.h"

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
	
		
		int	i = 0;
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
}
