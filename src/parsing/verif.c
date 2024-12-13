/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:17:06 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 20:14:43 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_in_game(char *line, char **texture, char **fc, int index)
{
	if (index >= 0 && index <= 3)
	{
		if (texture[index])
			free(texture[index]);
		texture[index] = ft_strdup(line);
	}
	else if (index == 4 || index == 5)
	{
		if (fc[index - 4])
			free(fc[index - 4]);
		fc[index - 4] = ft_strdup(line);
	}
	return (1);
}

int	check_id(char *line, char **texture, char **fc, int *verif)
{
	char			**id;

	id = ft_split(line, ' ');
	if (id == NULL)
		return (0);
	if (!ft_strcmp(*id, "NO"))
		*verif += put_in_game(line, texture, fc, 0);
	else if (!ft_strcmp(*id, "SO"))
		*verif += put_in_game(line, texture, fc, 1);
	else if (!ft_strcmp(*id, "WE"))
		*verif += put_in_game(line, texture, fc, 2);
	else if (!ft_strcmp(*id, "EA"))
		*verif += put_in_game(line, texture, fc, 3);
	else if (!ft_strcmp(*id, "F"))
		*verif += put_in_game(line, texture, fc, 4);
	else if (!ft_strcmp(*id, "C"))
		*verif += put_in_game(line, texture, fc, 5);
	else if (!ft_strcmp(*id, "\n"))
		return (free_map(id), 0);
	return (free_map(id), 1);
}

int	add_in_tab(char *line, char **texture, char **fc, int *verif)
{
	static int		i = 0;

	if (check_id(line, texture, fc, verif) == 1)
		i += 1;
	if (i > 6)
		return (0);
	else if (i == 6)
		return (2);
	return (1);
}

char	*file_to_tab(int fd, char **texture, char **fc)
{
	int		i;
	char	*trim_line;
	char	*line;
	int		verif;

	i = 0;
	verif = 0;
	line = ft_get_next_line(fd);
	skip_empty_line(&line, &fd);
	while (line != NULL)
	{
		trim_line = ft_strtrim(line, " ");
		free(line);
		line = ft_get_next_line(fd);
		i = add_in_tab(trim_line, texture, fc, &verif);
		free(trim_line);
		if (i == 0)
			return (free(line), NULL);
		else if (verif < 6 && i == 2)
			return (free(line), NULL);
		else if (i == 2)
			break ;
	}
	return (line);
}

int	verif_255(char *fc[2])
{
	int		i;
	int		value;
	char	*token;

	i = 0;
	while (i < 2)
	{
		token = fc[i] + 2;
		while (token)
		{
			value = ft_atoi_256(token);
			if (value > 255)
				return (0);
			token = ft_strchr(token, ',');
			if (token)
				token++;
		}
		i++;
	}
	return (1);
}
