/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:16:59 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 20:36:47 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	line_is_space(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == '0' || c == '1' || c == ' '
		|| c == 'W' || c == '2')
		return (1);
	return (0);
}

int	check_fd(int fd)
{
	if (fd == -1)
		return (0);
	else
		return (1);
}

void	skip_empty_line(char **line, int *fd)
{
	while (line != NULL && !line_is_space(*line))
	{
		free(*line);
		*line = ft_get_next_line(*fd);
		if (*line == NULL)
			return ;
	}
}
