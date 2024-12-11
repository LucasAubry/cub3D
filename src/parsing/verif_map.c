/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:17:04 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 18:17:05 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inc_multi_char(int *multi_char, char c)
{
	if (c == 'N')
		multi_char[0]++;
	else if (c == 'S')
		multi_char[1]++;
	else if (c == 'E')
		multi_char[2]++;
	else if (c == 'W')
		multi_char[3]++;
}

int	check_multi_char(int *multi_char)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (multi_char[i] > 1)
			return (0);
		if (multi_char[i] == 1)
			j++;
		i++;
	}
	if (j != 1)
		return (0);
	return (1);
}

int	verif_map(char **map)
{
	int	i;
	int	j;
	int	multi_char[4];

	i = 0;
	ft_bzero(multi_char, sizeof(multi_char));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_char(map[i][j]))
				return (0);
			inc_multi_char(multi_char, map[i][j]);
			j++;
		}
		i++;
	}
	if (!check_multi_char(multi_char))
		return (0);
	return (1);
}
