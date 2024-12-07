#ifndef CUB3D_H
#define CUB3D_H

/* ========== INCLUDE ============= */

#include "MLX42.h"
#include "libft.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"

/* ========== ENUM ================ */

/* ========== STRUCTURE =========== */

typedef struct s_color
{
    uint8_t        r;
    uint8_t        g;
    uint8_t        b;
}                t_color;

typedef struct s_textures
{
    mlx_texture_t    *n;
    mlx_texture_t    *s;
    mlx_texture_t    *w;
    mlx_texture_t    *e;
}                t_textures;

typedef struct s_game
{
	int	size_y;
	int	size_x;

	t_textures    textures;
	t_color        floor_color;
	t_color        ceiling_color;

	void	*mlx;
	char	**map;

}	t_game;


/* ========== ERROR ================*/

#define	FD "Error | fd"
#define FILES "Error | The file is not correct"
#define NOT_CUB "Error | File need be a .cub"
#define FILE_NOT_CORRECT "Error | The file name is not correct"
#define BAD_CHAR "Error | Bad char or multiple char in map"
#define BORDER_WALL "Error | No wall on all sides"
#define ERROR_255 "Error | RGB > 255"
#define COMMA "Error | Too much number for rgb"
#define CHAR_RGB "Error | Only number for rgb"

/* ========== FONCTION ============ */

int	parsing(t_game *game, char **argv);
int	check_fd(int fd);
int	verif_file_order(t_game *game, int fd);




int	check_char(char	c);
int	*check_multi_char(int *multi_char, char c);
int	verif_map(char **map);
int	verif_texture_fc(char	**texture, char **fc);
char	*skip_empty_line(char *line, int *fd);

#endif
