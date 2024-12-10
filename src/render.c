/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:12:45 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/10 14:19:38 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(void *param)
{
	t_game		*game;
	int			x;
	static int	i = 0;

	game = (t_game *)param;
	x = 0;
	draw_floor_and_ceiling(game);
	while (x < WIDTH)
	{
		render_column(game, x);
		x++;
	}
	render_minimap(game);
	draw_animation(game);
	if (i == 0)
	{
		mlx_image_to_window(game->mlx, game->screen, 0, 0);
	}
	i++;
}

void	render_column(t_game *game, int x)
{
	int	line_height;
	int	tex_x;

	calculate_ray_direction(game, x);
	init_dda(game);
	perform_dda(game);
	calculate_wall_distance(game, &line_height, &tex_x);
	draw_wall_line(game, x, line_height, tex_x);
}

void	render_minimap(t_game *game)
{
	int	minimap_size;
	int	tile_size;
	int	start_x;
	int	start_y;

	minimap_size = 125;
	tile_size = minimap_size / 5;
	start_x = game->player.pos_x - 2;
	start_y = game->player.pos_y - 2;
	draw_minimap(game, start_x, start_y, tile_size);
}
