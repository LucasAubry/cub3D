/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:59:16 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 02:12:52 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'N')
				init_n(&game->player, x, y);
			if (game->map[y][x] == 'S')
				init_s(&game->player, x, y);
			if (game->map[y][x] == 'W')
				init_w(&game->player, x, y);
			if (game->map[y][x] == 'E')
				init_e(&game->player, x, y);
			x++;
		}
		y++;
		x = 0;
	}
}

void	init_n(t_player *player, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

void	init_s(t_player *player, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

void	init_w(t_player *player, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	init_e(t_player *player, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}
