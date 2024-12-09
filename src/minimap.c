/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:28:10 by damdam            #+#    #+#             */
/*   Updated: 2024/12/09 17:18:25 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game, int start_x, int start_y, int tile_size)
{
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	uint32_t	color;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			map_x = start_x + x;
			map_y = start_y + y;
			if (is_valid_tile(game, map_x, map_y))
			{
				color = get_tile_color(game, map_x, map_y);
				draw_tile(game, x, y, tile_size, color);
			}
			x++;
		}
		y++;
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

void	draw_tile(t_game *game, int x, int y, int tile_size, uint32_t color)
{
	int	screen_x;
	int	screen_y;
	int	py;
	int	px;

	screen_x = 10 + x * tile_size;
	screen_y = 10 + y * tile_size;
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
