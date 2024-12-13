/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:16:51 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 16:57:02 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file(char **argv)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
	{
		ft_error("%s\n", NOT_CUB);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			point++;
		i++;
	}
	if (point > 1)
	{
		ft_error("%s\n", FILE_NOT_CORRECT);
		return (0);
	}
	return (1);
}

int	map(t_game *game, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	game->path_file = ft_strdup(argv[1]);
	if (!check_fd(fd))
	{
		ft_error("%s\n", FD);
		return (0);
	}
	if (!file_order(game, fd))
	{
		ft_error("%s\n", FILES);
		return (0);
	}
	len_of_map(game, game->map);
	return (1);
}

int	check_map(t_game *game)
{
	if (!verif_map(game->map))
	{
		ft_error("%s\n", BAD_CHAR);
		return (0);
	}
	verif_flood(game);
	return (1);
}

int	parsing(t_game *game, char **argv)
{
	if (!file(argv))
		return (0);
	if (!map(game, argv))
		return (0);
	if (!check_map(game))
		return (0);
	return (1);
}
