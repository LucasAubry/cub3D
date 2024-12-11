/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:18:02 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 18:18:03 by dalebran         ###   ########.fr       */
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

int	map_in_game(t_game *game, char *line, int fd, int len)
{
	game->map = malloc(sizeof(char *) * len);
	line = skip_empty_line(line, &fd);
	len = 0;
	while (line != NULL)
	{
		if (!line_is_space(line))
			break ;
		game->map[len] = ft_strtrim(line, "\n");
		free(line);
		line = ft_get_next_line(fd);
		len++;
	}
	if (line != NULL)
		return (0);
	game->map[len] = NULL;
	return (1);
}
