/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:16:56 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 22:04:59 by dalebran         ###   ########.fr       */
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
