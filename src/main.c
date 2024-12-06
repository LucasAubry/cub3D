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

void	render_frame(void *param)
{
	t_game		*game;
	int			x;
	int			hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			d;
	int			tex_y;
	uint32_t	color;
	mlx_texture_t *texture;

	game = (t_game *)param;
	x = 0;
	while (x < WIDTH)
	{
		// Calculer la position de la caméra pour chaque rayon
		game->ray.camera_x = 2 * x / (double)WIDTH - 1;
		game->ray.dir_x = game->player.dir_x + game->player.plane_x
			* game->ray.camera_x;
		game->ray.dir_y = game->player.dir_y + game->player.plane_y
			* game->ray.camera_x;
		// Définir la position actuelle sur la carte
		game->ray.map_x = (int)game->player.pos_x;
		game->ray.map_y = (int)game->player.pos_y;
		// Calculer la distance entre les côtés
		game->ray.deltadist_x = fabs(1 / game->ray.dir_x);
		game->ray.deltadist_y = fabs(1 / game->ray.dir_y);
		// Calculer la direction du pas (step) et la distance initiale au premier côté
		if (game->ray.dir_x < 0)
		{
			game->ray.step_x = -1;
			game->ray.sidedist_x = (game->player.pos_x - game->ray.map_x)
				* game->ray.deltadist_x;
		}
		else
		{
			game->ray.step_x = 1;
			game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.pos_x)
				* game->ray.deltadist_x;
		}
		if (game->ray.dir_y < 0)
		{
			game->ray.step_y = -1;
			game->ray.sidedist_y = (game->player.pos_y - game->ray.map_y)
				* game->ray.deltadist_y;
		}
		else
		{
			game->ray.step_y = 1;
			game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.pos_y)
				* game->ray.deltadist_y;
		}
		// Exécuter l'algorithme DDA pour trouver le mur
		hit = 0;
		while (hit == 0)
		{
			// Avancer au prochain carré de la grille
			if (game->ray.sidedist_x < game->ray.sidedist_y)
			{
				game->ray.sidedist_x += game->ray.deltadist_x;
				game->ray.map_x += game->ray.step_x;
				game->ray.side = 0; // Mur vertical touché
			}
			else
			{
				game->ray.sidedist_y += game->ray.deltadist_y;
				game->ray.map_y += game->ray.step_y;
				game->ray.side = 1; // Mur horizontal touché
			}
			// Vérifier si le rayon a touché un mur
			if (game->map[game->ray.map_y][game->ray.map_x] == '1')
				// Note: [map_y][map_x] est l'ordre correct pour accéder à la carte
				hit = 1;
		}
		// Calculer la distance perpendiculaire au mur
		if (game->ray.side == 0)
			game->ray.wall_dist = (game->ray.map_x - game->player.pos_x + (1
						- game->ray.step_x) / 2) / game->ray.dir_x;
		else
			game->ray.wall_dist = (game->ray.map_y - game->player.pos_y + (1
						- game->ray.step_y) / 2) / game->ray.dir_y;
		// Calculer wall_x
		if (game->ray.side == 0)
			wall_x = game->player.pos_y + game->ray.wall_dist * game->ray.dir_y;
		else
			wall_x = game->player.pos_x + game->ray.wall_dist * game->ray.dir_x;
		// On ne garde que la partie décimale pour le côté de la texture
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)T_WIDTH);
		if (game->ray.side == 0 && game->ray.dir_x > 0)
			tex_x = T_WIDTH - tex_x - 1;
		if (game->ray.side == 1 && game->ray.dir_y < 0)
			tex_x = T_WIDTH - tex_x - 1;
		// Calculer la hauteur de la ligne à dessiner sur l'écran
		line_height = (int)(HEIGHT / game->ray.wall_dist);
		// Calculer les points de début et de fin pour la ligne à dessiner
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		// Dessiner la ligne verticale pour représenter le mur
		for (int y = draw_start; y < draw_end; y++)
		{
			d = y * 256 - HEIGHT * 128 + line_height * 128;
			tex_y = ((d * T_HEIGHT) / line_height) / 256;
			// Sélection de la texture en fonction du mur touché
			if (game->ray.side == 0 && game->ray.dir_x > 0)
				texture = game->textures.e;
			else if (game->ray.side == 0 && game->ray.dir_x < 0)
				texture = game->textures.w;
			else if (game->ray.side == 1 && game->ray.dir_y > 0)
				texture = game->textures.s;
			else
				texture = game->textures.n;
			// Calcul de la position dans la texture
			if (texture)
			{
				int tex_offset = (tex_y * texture->width + tex_x) * 4;
					// Chaque pixel = 4 bytes (RGBA)
				color = (texture->pixels[tex_offset] << 24) | (texture->pixels[tex_offset
						+ 1] << 16) | (texture->pixels[tex_offset
						+ 2] << 8) | (texture->pixels[tex_offset + 3]);
			}
			else
			{
				color = 0xFFFFFFFF; // Blanc par défaut en cas d'échec
			}
			// Dessiner le pixel avec la couleur de la texture
			mlx_put_pixel(game->screen, x, y, color);
		}
		x++;
	}
	// Afficher l'image
	mlx_image_to_window(game->mlx, game->screen, 0, 0);
}

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
