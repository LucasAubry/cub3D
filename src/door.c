/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:47:24 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/09 16:59:19 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = (int)(game->player.pos_x + game->player.dir_x);
	target_y = (int)(game->player.pos_y + game->player.dir_y);
	if (game->map[target_y][target_x] == '2')
	{
		game->map[target_y][target_x] = '3';
		render_frame(game);
	}
	else if (game->map[target_y][target_x] == '3')
	{
		game->map[target_y][target_x] = '2';
		render_frame(game);
	}
}
