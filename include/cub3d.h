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

	t_textures    textures;
	t_color        floor_color;
	t_color        ceiling_color;

	void	*mlx;
	char	**map;
	char	*path_file;

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
#define DOUBLON_FILE "Error | Doublon in file"
#define CLOSE_MAP "Error | The map is not closed"

/* ========== FONCTION ============ */

int	parsing(t_game *game, char **argv);
int	check_fd(int fd);
int	file_order(t_game *game, int fd);

//fc
int	fc_in_game(t_game *game, char **fc);
int	fc_in_game(t_game *game, char **fc);
//texture
int	texture_in_game(t_game *game, char **texture);
int	texture_in_game(t_game *game, char **texture);
//map
int	map_in_game(t_game *game, char *line, int fd, int len);
char	*file_to_tab(int fd, char **texture, char **fc);
//verif map
int	verif_map(char **map);
void	verif_flood(t_game *game);





int	verif_map(char **map);
char	*skip_empty_line(char *line, int *fd);


//tools:
int	is_number(char c);
int	line_is_space(char *line);
int	check_char(char	c);
int	check_fd(int fd);
char	*skip_empty_line(char *line, int *fd);
void	len_of_map(t_game *game, char **map);
void	bz(int	*tab, int n);
void	bz_char(char *tab, int n);


#endif



//verif si pas de joueur
