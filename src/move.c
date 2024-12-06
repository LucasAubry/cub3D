/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:32:00 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/06 19:45:34 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	// Rotation du vecteur direction
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y
		* cos(angle);
	// Rotation du plan caméra (plane)
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y
		* cos(angle);
}

void	move_forward(t_game *game)
{
	// Vérifier que la case devant n'est pas un mur avant de déplacer
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
			+ game->player.dir_x * MOVE_SPEED)] != '1')
		game->player.pos_x += game->player.dir_x * MOVE_SPEED;
	if (game->map[(int)(game->player.pos_y + game->player.dir_y
			* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
		game->player.pos_y += game->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
			- game->player.dir_x * MOVE_SPEED)] != '1')
		game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
	if (game->map[(int)(game->player.pos_y - game->player.dir_y
			* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
		game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	double	perp_x;
	double	perp_y;

	// Déplacement latéral gauche (perpendiculaire à la direction)
	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x + perp_x
			* MOVE_SPEED)] != '1')
		game->player.pos_x += perp_x * MOVE_SPEED;
	if (game->map[(int)(game->player.pos_y + perp_y
			* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
		game->player.pos_y += perp_y * MOVE_SPEED;
}

void	move_right(t_game *game)
{
	double	perp_x;
	double	perp_y;

	perp_x = game->player.dir_y;
	perp_y = -game->player.dir_x;
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x + perp_x
			* MOVE_SPEED)] != '1')
		game->player.pos_x += perp_x * MOVE_SPEED;
	if (game->map[(int)(game->player.pos_y + perp_y
			* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
		game->player.pos_y += perp_y * MOVE_SPEED;
}
