/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:38:33 by damdam            #+#    #+#             */
/*   Updated: 2024/12/12 05:41:38 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	char	*path;

	game->textures.door = mlx_load_png("img/door.png");
	path = "anim/rc_knife/frame";
	init_knife_animation(game, &game->rc_anim, 3, path);
	path = "anim/lc_knife/frame";
	init_knife_animation(game, &game->lc_anim, 8, path);
	path = "anim/knife_v3/frame";
	init_knife_animation(game, &game->f_anim, 131, path);
	init_screen(game);
	init_player(game);
	init_ray(game);
}

void	init_screen(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		(free_game(game), free(game), exit(0));
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
}

void	init_ray(t_game *game)
{
	game->ray.camera_x = 0.0;
	game->ray.dir_x = game->player.dir_x;
	game->ray.dir_y = game->player.dir_y;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.sidedist_x = 0.0;
	game->ray.sidedist_y = 0.0;
	game->ray.deltadist_x = 0.0;
	game->ray.deltadist_y = 0.0;
	game->ray.wall_dist = 0.0;
	game->ray.side = -1;
	game->ray.wall_door = 0;
}

void	exit_game(t_game *game)
{
	mlx_close_window(game->mlx);
	free_game(game);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
