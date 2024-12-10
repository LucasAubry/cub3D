#include "cub3d.h"
#include "libft.h"

void	handle_input(void *param)
{
	t_game			*game;
	static uint64_t	last_render_time = 0;
	uint64_t		current_time;

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
	current_time = mlx_get_time() * 1000;
	if (current_time - last_render_time >= 1000 / FRAME_RATE)
	{
		render_frame(game);
		last_render_time = current_time;
	}
}

void	animations(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_SPACE)
			open_door(game);
		if (keydata.key == MLX_KEY_E)
			game->k_anim.playing = 1;
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

void	handle_mouse(double xpos, double ypos, void *param)
{
	t_game	*game;
	double	delta_x;
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	game = (t_game *)param;
	delta_x = xpos - (WIDTH / 2);
	(void)ypos;
	// Réinitialiser la position de la souris au centre
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	// Calcul de l'angle de rotation
	angle = delta_x * (ROT_SPEED/70);
	// Appliquer la rotation au vecteur directionnel
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y
		* cos(angle);
	// Appliquer la rotation au plan de la caméra
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y
		* cos(angle);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	(void)argc;
	game = initGame();
	print_map(game->map);
	render_frame(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_cursor_hook(game->mlx, handle_mouse, game);
	mlx_close_hook(game->mlx, (mlx_closefunc)freeGame, game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_key_hook(game->mlx, animations, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
