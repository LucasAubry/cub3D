/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:38:33 by damdam            #+#    #+#             */
/*   Updated: 2024/12/09 17:00:02 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*initGame(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	initMap(game);
	initPlayer(game);
	initTextures(game);
	initRay(game);
	return (game);
}

void	initPlayer(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
			}
			if (game->map[y][x] == 'N')
			{
				game->player.dir_x = 0;
				game->player.dir_y = -1;
				game->player.plane_x = 0.66;
				game->player.plane_y = 0;
			}
			if (game->map[y][x] == 'S')
			{
				game->player.dir_x = 0;
				game->player.dir_y = 1;
				game->player.plane_x = -0.66;
				game->player.plane_y = 0;
			}
			if (game->map[y][x] == 'W')
			{
				game->player.dir_x = -1;
				game->player.dir_y = 0;
				game->player.plane_x = 0;
				game->player.plane_y = 0.66;
			}
			if (game->map[y][x] == 'E')
			{
				game->player.dir_x = 1;
				game->player.dir_y = 0;
				game->player.plane_x = 0;
				game->player.plane_y = -0.66;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	initMap(t_game *game)
{
	int		i;
	char	*raw_map[] = {"1111111111\0", "1000000001\0", "1011211101\0",
			"1N00000001\0", "1111111111\0", NULL};

	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->map = malloc(sizeof(char *) * 6);
	i = 0;
	while (raw_map[i])
	{
		game->map[i] = ft_strdup(raw_map[i]);
		i++;
	}
	game->map[i] = NULL;
}

void	initTextures(t_game *game)
{
	game->ceiling_color.r = 50;
	game->ceiling_color.g = 50;
	game->ceiling_color.b = 50;
	game->floor_color.r = 20;
	game->floor_color.g = 20;
	game->floor_color.b = 20;
	game->textures.n = mlx_load_png("img/blue_wall.png");
	game->textures.s = mlx_load_png("img/purple_wall.png");
	game->textures.e = mlx_load_png("img/grey_wall.png");
	game->textures.w = mlx_load_png("img/yellow_wall.png");
	game->textures.door = mlx_load_png("img/door.png");
}

void	initRay(t_game *game)
{
	game->ray.camera_x = 0.0;
	game->ray.dir_x = game->player.dir_x;
	game->ray.dir_y = game->player.dir_y;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.sidedist_x = 0.0;
	game->ray.sidedist_y = 0.0;
	game->ray.deltadist_x = 0.0;
	game->ray.deltadist_y = 0.0;
	game->ray.wall_dist = 0.0;
	game->ray.side = -1;
	game->ray.wall_door = 0;
}

void	printMap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}