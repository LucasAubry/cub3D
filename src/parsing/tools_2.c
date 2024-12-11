/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:16:56 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 23:35:09 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	len_of_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	game->size_y = i;
}

void	bz(int *tab, int n)
{
	int	i;

	i = 0;
	while (i != n)
	{
		tab[i] = 0;
		i++;
	}
}

void	free_texture(char **map, int taille)
{
	int	i;

	i = 0;
	while (i < taille)
	{
		free(map[i]);
		i++;
	}
}

void	free_parsing(t_game *game)
{
	if (game->textures.n != NULL)
		mlx_delete_texture(game->textures.n);
	if (game->textures.s != NULL)
		mlx_delete_texture(game->textures.s);
	if (game->textures.e != NULL)
		mlx_delete_texture(game->textures.e);
	if (game->textures.w != NULL)
		mlx_delete_texture(game->textures.w);
	if (game->path_file)
		free(game->path_file);
	if (game->map)
		free_map(game->map);
}
