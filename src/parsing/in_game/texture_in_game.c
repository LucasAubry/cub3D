/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:18:05 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 16:33:31 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_path(char **path, char *temp_path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(temp_path);
	free(path);
}

char	**path_to_texture(char **texture)
{
	char	**path;
	char	*temp_path;
	int		i;

	i = 0;
	while (i != 4)
	{
		path = ft_split(texture[i], ' ');
		temp_path = ft_strtrim(path[1], "\n");
		if (path[2])
		{
			free_path(path, temp_path);
			return (NULL);
		}
		if (temp_path)
		{
			free(texture[i]);
			texture[i] = ft_strdup(temp_path);
		}
		free_path(path, temp_path);
		i++;
	}
	return (texture);
}

int	texture_in_game(t_game *game, char **texture)
{
	texture = path_to_texture(texture);
	if (texture == NULL)
		return (0);
	game->textures.n = mlx_load_png(texture[0]);
	game->textures.s = mlx_load_png(texture[1]);
	game->textures.e = mlx_load_png(texture[2]);
	game->textures.w = mlx_load_png(texture[3]);
	if (game->textures.n == NULL || game->textures.s == NULL
		|| game->textures.e == NULL || game->textures.w == NULL)
	{
		return (0);
	}
	return (1);
}
