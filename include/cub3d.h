#ifndef CUB3D_H
#define CUB3D_H

/* ========== INCLUDE ============= */

#include "MLX42.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"

/* ========== ENUM ================ */

/* ========== STRUCTURE =========== */

typedef struct s_game
{
	int	size_y;
	int	size_x;

	void	*mlx;
	char	**map;

}	t_game;


/* ========== ERROR ================*/

#define	FD "Error fd"
#define NOT.CUB "File need be a .cub"
#define FILE_NOT_CORRECT "The file name is not correct"
#define BAD_CHAR "Bad char or multiple char in map"
#define BORDER_WALL "No wall on all sides"

/* ========== FONCTION ============ */

int	check_fd(int fd);
int	check_char(char	c);
int	*check_multi_char(int *multi_char, char c);
int	verif_map(char **map);

#endif
