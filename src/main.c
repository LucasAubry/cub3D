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
		rotate_player(game, -ROT_SPEED); // Tourner à gauche
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROT_SPEED); // Tourner à droite
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
	// mlx_close_hook(game->mlx, (mlx_closefunc)free_game, game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
}
