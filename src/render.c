/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:12:45 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/06 18:01:54 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(void *param)
{
	t_game		*game;
	int			x;

	game = (t_game *)param;
	x = 0;
	while (x < WIDTH)
	{
		render_column(game, x);
		x++;
	}
	// Afficher l'image
	mlx_image_to_window(game->mlx, game->screen, 0, 0);
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
