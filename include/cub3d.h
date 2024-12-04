#ifndef CUB3D_H
# define CUB3D_H

/* ========== INCLUDE ============= */

# include "MLX42.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"
# include <stdint.h>

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
	mlx_image_t		*n_texture;
	mlx_image_t		*s_texture;
	mlx_image_t		*w_texture;
	mlx_image_t		*e_texture;
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
	int			p_start_x;
	int			p_start_y;
	char		p_direction;
	void		*mlx;
}				t_game;

/* ========== ERROR ================*/

/* ========== FONCTION ============ */

#endif
