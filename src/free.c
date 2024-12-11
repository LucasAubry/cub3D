/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:21:26 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 02:21:58 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
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
	free_game(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
