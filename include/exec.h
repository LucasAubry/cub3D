#pragma once

# include "cub3d.h"
# include "MLX42/MLX42.h"
# include <math.h>

typedef struct s_game t_game;

// init.c
t_game	*initGame(void);
void	initPos(t_game *game);
void	initMap(t_game *game);
void	initImage(t_game *game);
void	printMap(char **map);

mlx_image_t	*load_image(mlx_t *mlx, const char *path);