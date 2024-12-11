/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:28:10 by damdam            #+#    #+#             */
/*   Updated: 2024/12/11 02:32:23 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game, t_xy start, int tile_size)
{
	t_xy		xy;
	int			map_x;
	int			map_y;
	uint32_t	color;

	xy.y = 0;
	while (xy.y < 5)
	{
		xy.x = 0;
		while (xy.x < 5)
		{
			map_x = start.x + xy.x;
			map_y = start.y + xy.y;
			if (is_valid_tile(game, map_x, map_y))
			{
				color = get_tile_color(game, map_x, map_y);
				draw_tile(game, xy, tile_size, color);
			}
			xy.x++;
		}
		xy.y++;
	}
}

int	is_valid_tile(t_game *game, int map_x, int map_y)
{
	return (map_y >= 0 && map_x >= 0 && game->map[map_y] != NULL
		&& game->map[map_y][map_x] != '\0');
}

uint32_t	get_tile_color(t_game *game, int map_x, int map_y)
{
	if (map_x == (int)game->player.pos_x && map_y == (int)game->player.pos_y)
		return (0xFF0000FF);
	if (game->map[map_y][map_x] == '2' || game->map[map_y][map_x] == '3')
		return (0x808080FF);
	if (game->map[map_y][map_x] == '0' || game->map[map_y][map_x] == 'N'
		|| game->map[map_y][map_x] == 'S' || game->map[map_y][map_x] == 'E'
		|| game->map[map_y][map_x] == 'W')
		return (0xFFFFFFFF);
	return (0x000000FF);
}

void	draw_tile(t_game *game, t_xy xy, int tile_size, uint32_t color)
{
	int	screen_x;
	int	screen_y;
	int	py;
	int	px;

	screen_x = 10 + xy.x * tile_size;
	screen_y = 10 + xy.y * tile_size;
	py = 0;
	while (py < tile_size)
	{
		px = 0;
		while (px < tile_size)
		{
			mlx_put_pixel(game->screen, screen_x + px, screen_y + py, color);
			px++;
		}
		py++;
	}
}
