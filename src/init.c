/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:38:33 by damdam            #+#    #+#             */
/*   Updated: 2024/12/05 16:17:25 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*initGame(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	initPos(game);
	initMap(game);
	initImage(game);
	return (game);
}

void	initPos(t_game *game)
{
	game->pos_x = 3;
	game->pos_y = 3;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
}

void	initMap(t_game *game)
{
	int		i;
	char	*raw_map[] = {"1111111111\0", "1000000001\0", "1011111101\0",
			"100N000001\0", "1111111111\0", NULL};

	game->mlx = mlx_init(980, 720, "cub3D", false);
	game->map = malloc(sizeof(char *) * 6);
	i = 0;
	while (raw_map[i])
	{
		game->map[i] = ft_strdup(raw_map[i]);
		i++;
	}
	game->map[i] = NULL;
}

void	initImage(t_game *game)
{
	game->textures.n_texture = load_image(game->mlx, "img/blue_wall.png");
	game->textures.s_texture = load_image(game->mlx, "img/purple_wall.png");
	game->textures.e_texture = load_image(game->mlx, "img/grey_wall.png");
	game->textures.w_texture = load_image(game->mlx, "img/yellow_wall.png");
}

void	printMap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}