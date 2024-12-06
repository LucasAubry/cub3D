/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:12:45 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/06 20:06:22 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	printData(t_game *game)
{
	printf("pos_x : %lf | pos_y : %lf | dir_x : %lf | dir_y : %lf | plane_x : %lf | plane_y : %lf\n", game->player.pos_x, game->player.pos_y, game->player.dir_x, game->player.dir_y, game->player.plane_x, game->player.plane_y);
	printf("ray.dir_x : %lf | ray.dir_y : %lf\n", game->ray.dir_x, game->ray.dir_y);
}

void	render_frame(void *param)
{
	t_game		*game;
	int			x;

	game = (t_game *)param;
	x = 0;
	draw_floor_and_ceiling(game);
	while (x < WIDTH)
	{
		render_column(game, x);
		x++;
	}
	// Afficher l'image
	printData(game);
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
