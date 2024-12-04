#include "cub3d.h"

// void	loop(t_game *game)
// {
// 	mlx_loop_hook(game->mlx, &set_key, game);
// 	mlx_loop(game->mlx);
// 	//free;
// }

// int	set_mlx(t_game *game)
// {
// 	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
// 	if (!game->mlx)
// 		return (0);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_game	*game;
	
	(void)argv;
	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		game->mlx = mlx_init(game->size_x * 64, game->size_y * 64, "cub3D", true);
		// if (!set_mlx(game))
		// 	return (0);
	}
	//loop(game);
}
