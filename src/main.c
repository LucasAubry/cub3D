#include "cub3d.h"
#include "libft.h"

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->textures.n_texture)
			mlx_delete_image(game->mlx, game->textures.n_texture);
		if (game->textures.s_texture)
			mlx_delete_image(game->mlx, game->textures.s_texture);
		if (game->textures.e_texture)
			mlx_delete_image(game->mlx, game->textures.e_texture);
		if (game->textures.w_texture)
			mlx_delete_image(game->mlx, game->textures.w_texture);
		free_map(game->map);
		free(game);
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

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

t_game	*initGame()
{
	t_game	*game;
	int		i;
	char	*raw_map[] = {
		"1111111111\0",
		"1000000001\0",
		"1011111101\0",
		"100N000001\0",
		"1111111111\0",
		NULL
	};

	game = malloc(sizeof(t_game));
	//game->mlx = mlx_init(980, 720, "cub3D", true);
	game->map = malloc(sizeof(char *) * 6);
	i = 0;
	while (raw_map[i])
	{
		game->map[i] = ft_strdup(raw_map[i]);
		i++;
	}
	game->map[i] = NULL;
	//free_map(raw_map);
	return (game);
}

void	printMap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	(void)argv;
	(void)argc;
	game = initGame();
	print_map(game->map);
	free_game(game);
	
	//mlx_key_hook(game->mlx, move_player, game);
	//mlx_close_hook(game->mlx, (mlx_closefunc)free_game, game);
	//mlx_loop_hook(game->mlx, animate_wall, game);
	//mlx_loop(game->mlx);
}
