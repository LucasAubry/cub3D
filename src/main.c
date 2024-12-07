#include "cub3d.h"
#include "libft.h"

void	handle_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_F))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_R))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_T))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		rotate_player(game, -ROT_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_P))
		rotate_player(game, ROT_SPEED);
}

void	freeGame(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_delete_texture(game->textures.n);
	mlx_delete_texture(game->textures.s);
	mlx_delete_texture(game->textures.w);
	mlx_delete_texture(game->textures.e);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	(void)argc;
	game = initGame();
	print_map(game->map);
	render_frame(game);
	// mlx_key_hook(game->mlx, handle_input, game);
	mlx_close_hook(game->mlx, (mlx_closefunc)freeGame, game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
