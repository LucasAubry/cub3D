/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:18:02 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 16:33:45 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	have_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

int	map_in_game(t_game *game, char **line, int fd, int len)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * len);
	while (i < len)
	{
		game->map[i] = NULL;
		i++;
	}
	skip_empty_line(&(*line), &fd);
	len = 0;
	while (*line != NULL)
	{
		if (!line_is_space(*line))
			break ;
		game->map[len] = ft_strtrim(*line, "\n");
		free(*line);
		*line = ft_get_next_line(fd);
		len++;
	}
	if (*line != NULL)
		return (0);
	game->map[len] = NULL;
	return (1);
}
