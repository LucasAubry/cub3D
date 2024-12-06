#include "cub3d.h"
#include "libft.h"

// void	free_game(t_game *game)
// {
// 	if (game)
// 	{
// 		if (game->textures.n_img)
// 			mlx_delete_image(game->mlx, game->textures.n_img);
// 		if (game->textures.s_img)
// 			mlx_delete_image(game->mlx, game->textures.s_img);
// 		if (game->textures.e_img)
// 			mlx_delete_image(game->mlx, game->textures.e_img);
// 		if (game->textures.w_img)
// 			mlx_delete_image(game->mlx, game->textures.w_img);
// 		free_map(game->map);
// 		free(game);
// 	}
// }

// void	free_map(char **map)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

// void	move_player(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*game;
// 	int		new_row;
// 	int		new_col;
// 	game = (t_game *)param;
// 	new_row = game->p_row;
// 	new_col = game->p_col;
// 	if (keydata.action == MLX_PRESS)
// 	{
// 		if (keydata.key == MLX_KEY_ESCAPE)
// 			handle_escape_key(game);
// 		else
// 		{
// 			check_direction(keydata, game, &new_row, &new_col);
// 			if (new_row != game->p_row || new_col != game->p_col)
// 				handle_move(game, new_row, new_col);
// 		}
// 	}
// }

// void	animate_wall(void *param)
// {
// 	t_game		*game;
// 	static int	last_time;
// 	int			current_time;
// 	int			row;
// 	int			col;
// 	game = (t_game *)param;
// 	current_time = mlx_get_time();
// 	if (current_time - last_time >= 1)
// 	{
// 		last_time = current_time;
// 		if (game->cur_wall == 0)
// 			game->cur_wall = 1;
// 		else
// 			game->cur_wall = 0;
// 		row = -1;
// 		while (game->map[++row])
// 		{
// 			col = -1;
// 			while (game->map[row][++col])
// 				if (game->map[row][col] == '1')
// 					DRAW_IMG(game->mlx, game->assets.wall[game->cur_wall],
// 						col * T_S, row * T_S);
// 		}
// 	}
// }

// void	move_player(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*game;
// 	double	moveSpeed;

// 	game = (t_game *)param;
// 	moveSpeed = 0.1;
// 	double newPosX, newPosY;
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 	{
// 		newPosX = game->pos_x + game->dir_x * moveSpeed;
// 		newPosY = game->pos_y + game->dir_y * moveSpeed;
// 		if (game->map[(int)newPosY][(int)game->pos_x] != '1')
// 			game->pos_y = newPosY;
// 		if (game->map[(int)game->pos_y][(int)newPosX] != '1')
// 			game->pos_x = newPosX;
// 	}
// 	// Ajoutez les autres contrôles (S, A, D) ici pour reculer ou tourner
// }

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	(void)argc;
	game = initGame();
	print_map(game->map);
	// mlx_key_hook(game->mlx, move_player, game);
	// mlx_close_hook(game->mlx, (mlx_closefunc)free_game, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}
