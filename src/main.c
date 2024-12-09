#include "cub3d.h"
#include "libft.h"

void	handle_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, -ROT_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROT_SPEED);
}

void	animations(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_SPACE)
			open_door(game);
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit_game(game);
	}
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
	mlx_delete_texture(game->textures.door);
}

void	exit_game(t_game *game)
{
	mlx_close_window(game->mlx);
	freeGame(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	(void)argc;
	game = initGame();
	print_map(game->map);
	render_frame(game);
	
	mlx_close_hook(game->mlx, (mlx_closefunc)freeGame, game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_key_hook(game->mlx, animations, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
