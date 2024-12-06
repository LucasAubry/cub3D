#pragma once

/* ========== INCLUDE ============= */

#include "MLX42/MLX42.h"
#include "libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <math.h>
#include <stdint.h>

#define WIDTH 980
#define HEIGHT 720
#define T_WIDTH 64
#define T_HEIGHT 64
#define MOVE_SPEED 0.08
#define ROT_SPEED 0.08

/* ========== ENUM ================ */

/* ========== STRUCTURE =========== */

typedef struct s_draw_limits
{
	int				start;
	int				end;
}					t_draw_limits;

// Structure pour stocker les couleurs RGB
typedef struct s_color
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_color;

// Structure pour les textures
typedef struct s_textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
}					t_textures;

// Structure pour les informations du joueur
typedef struct s_player
{
	double pos_x;   // Position actuelle X du joueur
	double pos_y;   // Position actuelle Y du joueur
	double dir_x;   // Direction actuelle X du joueur
	double dir_y;   // Direction actuelle Y du joueur
	double plane_x; // Plan de caméra X (pour définir le FOV)
	double plane_y; // Plan de caméra Y (pour définir le FOV)
}					t_player;

// Structure pour les informations du rayon utilisé pour le raycasting
typedef struct s_ray
{
	double camera_x; // Position du rayon sur le plan caméra (de -1 à 1)
	double dir_x;    // Direction X du rayon (calculée pour chaque colonne)
	double dir_y;    // Direction Y du rayon (calculée pour chaque colonne)
	int				map_x;
	// Coordonnée X de la grille sur laquelle le rayon est actuellement
	int				map_y;
	// Coordonnée Y de la grille sur laquelle le rayon est actuellement
	int step_x;        // Direction à suivre en X (+1 ou -1)
	int step_y;        // Direction à suivre en Y (+1 ou -1)
	double sidedist_x; // Distance du point de départ au premier côté vertical
	double			sidedist_y;
	// Distance du point de départ au premier côté horizontal
	double deltadist_x; // Distance entre deux côtés verticaux de la grille
	double deltadist_y; // Distance entre deux côtés horizontaux de la grille
	double wall_dist;   // Distance perpendiculaire du joueur au mur touché
	int side;           // Indique quel côté du mur a été touché
}					t_ray;

// Structure principale contenant les informations du jeu
typedef struct s_game
{
	int				size_y;
	int				size_x;
	t_textures		textures;
	t_color			floor_color;
	t_color			ceiling_color;
	char			**map;
	t_player		player;
	t_ray			ray;
	mlx_image_t		*screen;
	mlx_t			*mlx;
}					t_game;

/* ========== ERROR ================*/

/* ========== FONCTION ============ */

// main.c
void				handle_input(void *param);

// init.c
t_game				*initGame(void);
void				initPlayer(t_game *game);
void				initMap(t_game *game);
void				initTextures(t_game *game);
void				printMap(char **map);
void				initRay(t_game *game);

// line_drawing.c
t_draw_limits		calculate_draw_limits(int line_height);
void				draw_wall_line(t_game *game, int x, int line_height,
						int tex_x);
void				draw_floor_and_ceiling(t_game *game);

// raycasting.c
void				calculate_ray_direction(t_game *game, int x);
void				init_dda(t_game *game);
void				perform_dda(t_game *game);
void				calculate_wall_distance(t_game *game, int *line_height,
						int *tex_x);

// render.c
void				render_frame(void *param);
void				render_column(t_game *game, int x);
void				printData(t_game *game);

// texture.c
mlx_texture_t		*select_texture(t_game *game);
uint32_t			get_texture_color(mlx_texture_t *texture, int tex_x,
						int tex_y);
uint32_t			rgb_to_rgba(unsigned char r, unsigned char g,
						unsigned char b);

// move.c
void				rotate_player(t_game *game, double angle);
void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);