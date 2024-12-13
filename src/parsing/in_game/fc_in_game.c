/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_in_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:17:54 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 16:58:17 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_color(char **rgb, uint8_t *color, int *color_index)
{
	char	color_str[16];
	int		i;

	i = 0;
	while (**rgb == ' ' || **rgb == '\t')
		(*rgb)++;
	ft_bzero(color_str, sizeof(color_str));
	while (is_number(**rgb))
		color_str[i++] = *(*rgb)++;
	if (**rgb != '\0' && **rgb != ',' && **rgb != ' ' && **rgb != '\t')
		return (0);
	color[*color_index] = (uint8_t)ft_atoi(color_str);
	(*color_index)++;
	if (**rgb == ',')
		(*rgb)++;
	return (1);
}

int	fc_to_tab(uint8_t *floor_cel, char **fc, int i)
{
	char	*rgb;
	int		color_index;
	int		color_count;

	color_index = 0;
	color_count = 0;
	rgb = ft_strchr(fc[i], ' ');
	while (*rgb != '\0')
	{
		if (!extract_color(&rgb, floor_cel, &color_index))
			return (0);
		color_count++;
	}
	if (color_count != 3)
		return (0);
	return (1);
}

int	verif_comma(char **fc)
{
	int	i;
	int	v;
	int	v1;

	i = 0;
	v = 0;
	v1 = 0;
	while (fc[0][i] && fc[1][i])
	{
		if (fc[0][i] == ',')
			v++;
		if (fc[1][i] == ',')
			v1++;
		i++;
	}
	if (v > 2 || v1 > 2)
		return (0);
	return (1);
}

int	select_fc(uint8_t *floor, uint8_t *ceiling, char **fc)
{
	char	*tmp[2];

	tmp[0] = ft_strtrim(fc[0], "\n");
	tmp[1] = ft_strtrim(fc[1], "\n");
	free_texture(fc, 2);
	fc[0] = tmp[0];
	fc[1] = tmp[1];
	if (!verif_comma(fc))
	{
		ft_error("%s\n", COMMA);
		return (0);
	}
	if (!verif_255(fc))
	{
		ft_error("%s\n", ERROR_255);
		return (0);
	}
	if (!fc_to_tab(floor, fc, 0) || !fc_to_tab(ceiling, fc, 1))
	{
		ft_error("%s\n", CHAR_RGB);
		return (0);
	}
	return (1);
}

int	fc_in_game(t_game *game, char **fc)
{
	uint8_t	floor[3];
	uint8_t	ceiling[3];

	if (!select_fc(floor, ceiling, fc))
	{
		return (0);
	}
	game->floor_color.r = floor[0];
	game->floor_color.g = floor[1];
	game->floor_color.b = floor[2];
	game->ceiling_color.r = ceiling[0];
	game->ceiling_color.g = ceiling[1];
	game->ceiling_color.b = ceiling[2];
	return (1);
}
