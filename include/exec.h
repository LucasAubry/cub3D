#pragma once

#include "MLX42/MLX42.h"
#include "cub3d.h"
#include <math.h>

typedef struct s_game	t_game;

// init.c
t_game					*initGame(void);
void					initPlayer(t_game *game);
void					initMap(t_game *game);
void					initTextures(t_game *game);
void					printMap(char **map);
void					initRay(t_game *game);

mlx_image_t				*load_image(mlx_t *mlx, const char *path);