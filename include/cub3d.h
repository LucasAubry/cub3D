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

#define WIDTH 980
#define HEIGHT 720
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

// Structure pour les informations du joueur
typedef struct s_player
{
	double		pos_x;      // Position actuelle X du joueur
	double		pos_y;      // Position actuelle Y du joueur
	double		dir_x;      // Direction actuelle X du joueur
	double		dir_y;      // Direction actuelle Y du joueur
	double		plane_x;    // Plan de caméra X (pour définir le FOV)
	double		plane_y;    // Plan de caméra Y (pour définir le FOV)
}				t_player;

// Structure pour les informations du rayon utilisé pour le raycasting
typedef struct s_ray
{
	double	camera_x;    // Position du rayon sur le plan caméra (de -1 à 1)
	double	dir_x;       // Direction X du rayon (calculée pour chaque colonne)
	double	dir_y;       // Direction Y du rayon (calculée pour chaque colonne)
	int		map_x;       // Coordonnée X de la grille sur laquelle le rayon est actuellement
	int		map_y;       // Coordonnée Y de la grille sur laquelle le rayon est actuellement
	int		step_x;      // Direction à suivre en X (+1 ou -1)
	int		step_y;      // Direction à suivre en Y (+1 ou -1)
	double	sidedist_x;  // Distance du point de départ au premier côté vertical
	double	sidedist_y;  // Distance du point de départ au premier côté horizontal
	double	deltadist_x; // Distance entre deux côtés verticaux de la grille
	double	deltadist_y; // Distance entre deux côtés horizontaux de la grille
	double	wall_dist;   // Distance perpendiculaire du joueur au mur touché
	int		side;        // Indique quel côté du mur a été touché (0 pour x, 1 pour y)
}				t_ray;

// Structure principale contenant les informations du jeu
typedef struct s_game
{
	int			size_y;
	int			size_x;
	t_textures	textures;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	t_player	player;
	t_ray		ray;
	mlx_image_t	*screen;
	mlx_t		*mlx;
}				t_game;


/* ========== ERROR ================*/

/* ========== FONCTION ============ */
