#pragma once

/* ========== INCLUDE ============= */

#include "exec.h"
#include "libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "MLX42/MLX42.h"
#include <stdint.h>

/* ========== ENUM ================ */

/* ========== STRUCTURE =========== */

// Structure pour stocker les couleurs RGB
typedef struct s_color
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_color;

// Structure pour les textures
typedef struct s_textures
{
	mlx_image_t	*n_texture;
	mlx_image_t	*s_texture;
	mlx_image_t	*w_texture;
	mlx_image_t	*e_texture;
}				t_textures;

typedef struct s_game
{
	int			size_y;
	int			size_x;
	t_textures	textures;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	double pos_x;   // Position actuelle X du joueur
	double pos_y;   // Position actuelle Y du joueur
	double dir_x;   // Direction actuelle X du joueur
	double dir_y;   // Direction actuelle Y du joueur
	double plane_x; // Plan de caméra X (pour définir le FOV)
	double plane_y; // Plan de caméra Y (pour définir le FOV)
	mlx_image_t	*screen;
	mlx_t		*mlx;
}				t_game;

/* ========== ERROR ================*/

/* ========== FONCTION ============ */
