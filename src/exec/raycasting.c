/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:14:31 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 02:33:41 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_direction(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)WIDTH - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x
		* game->ray.camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y
		* game->ray.camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.deltadist_x = fabs(1 / game->ray.dir_x);
	game->ray.deltadist_y = fabs(1 / game->ray.dir_y);
}

void	init_dda(t_game *game)
{
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
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1'
			|| game->map[game->ray.map_y][game->ray.map_x] == '2')
			hit = 1;
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.wall_door = 0;
		if (game->map[game->ray.map_y][game->ray.map_x] == '2')
			game->ray.wall_door = 1;
	}
}

void	calculate_wall_distance(t_game *game, int *line_height, int *tex_x)
{
	double	wall_x;

	if (game->ray.side == 0)
		game->ray.wall_dist = (game->ray.map_x - game->player.pos_x + (1
					- game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.wall_dist = (game->ray.map_y - game->player.pos_y + (1
					- game->ray.step_y) / 2) / game->ray.dir_y;
	if (game->ray.side == 0)
		wall_x = game->player.pos_y + game->ray.wall_dist * game->ray.dir_y;
	else
		wall_x = game->player.pos_x + game->ray.wall_dist * game->ray.dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)T_WIDTH);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		*tex_x = T_WIDTH - *tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		*tex_x = T_WIDTH - *tex_x - 1;
	*line_height = (int)(HEIGHT / game->ray.wall_dist);
}
