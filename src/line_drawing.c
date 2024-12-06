/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:15:45 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/06 17:15:55 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_draw_limits	calculate_draw_limits(int line_height)
{
	t_draw_limits	limits;

	// Calculer les points de début et de fin pour la ligne à dessiner
	limits.start = -line_height / 2 + HEIGHT / 2;
	if (limits.start < 0)
		limits.start = 0;
	limits.end = line_height / 2 + HEIGHT / 2;
	if (limits.end >= HEIGHT)
		limits.end = HEIGHT - 1;
	return (limits);
}

void	draw_wall_line(t_game *game, int x, int line_height, int tex_x)
{
	t_draw_limits	limits;
	int				y;
	int				d;
	int				tex_y;
	mlx_texture_t	*texture;

	limits = calculate_draw_limits(line_height);
	texture = select_texture(game);
	y = limits.start;
	while (y < limits.end)
	{
		d = y * 256 - HEIGHT * 128 + line_height * 128;
		tex_y = ((d * T_HEIGHT) / line_height) / 256;
		mlx_put_pixel(game->screen, x, y, get_texture_color(texture, tex_x, tex_y));
		y++;
	}
}
