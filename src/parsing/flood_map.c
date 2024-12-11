/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:16:48 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 23:11:13 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_row_map(char **map)
{
	int	raw;

	raw = 0;
	while (map[raw])
		raw++;
	return (raw);
}

char	**copy_map(char **map)
{
	int		i;
	int		row;
	char	**copy_map;

	row = calc_row_map(map);
	copy_map = (char **)malloc(sizeof(char *) * (row + 1));
	if (!copy_map)
		return (free_map(copy_map), NULL);
	ft_memset(copy_map, 0, sizeof(char *) * (row + 1));
	i = 0;
	while (i < row)
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[row] = NULL;
	return (copy_map);
}

void	player_position(t_game *game, char **map, int *i, int *j)
{
	*i = 0;
	while (*i < game->size_y)
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'N' || map[*i][*j] == 'E'
				|| map[*i][*j] == 'S' || map[*i][*j] == 'W')
				return ;
			(*j)++;
		}
		(*i)++;
	}
	return ;
}

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->size_y || y >= (int)ft_strlen(map[x]))
	{
		ft_error("%s\n", CLOSE_MAP);
		free_map(map);
		free_parsing(game);
		free(game);
		exit(1);
	}
	if (map[x][y] == '\0' || map[x][y] == ' ')
	{
		ft_error("%s\n", CLOSE_MAP);
		free_map(map);
		free_parsing(game);
		free(game);
		exit(1);
	}
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x, y + 1);
}

void	verif_flood(t_game *game)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = copy_map(game->map);
	player_position(game, game->map, &i, &j);
	flood_fill(game, temp_map, i, j);
	free_map(temp_map);
}
