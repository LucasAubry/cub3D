#include "cub3d.h"

// void	loop(t_game *game)
// {
// 	mlx_loop_hook(game->mlx, &set_key, game);
// 	mlx_loop(game->mlx);
// 	//free;
// }

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
//		game->mlx = mlx_init(game->size_x * 64, game->size_y * 64, "cub3D", true);
//		if (!set_mlx(game))
//		{
//			printf("mlx errro");
//		 	return (0);
//		}
		if (!parsing(game, argv))
		{
			printf("MAIN PARSING");
			return (0);
		}
	

		printf("%u\n", game->floor_color.r);
		printf("%u\n", game->floor_color.g);
		printf("%u\n", game->floor_color.b);
		printf("\n");
		printf("%u\n", game->ceiling_color.r);
		printf("%u\n", game->ceiling_color.g);
		printf("%u\n", game->ceiling_color.b);
	}
//	loop(game);
}
