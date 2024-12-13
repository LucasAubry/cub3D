/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:36:36 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 20:10:01 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define WIDTH 854
#define HEIGHT 480
#define T_WIDTH 64
#define T_HEIGHT 64
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.12
#define MAP_SIZE 150
#define FRAME_RATE 30

/* ========== ENUM ================ */

/* ========== STRUCTURE =========== */

typedef struct s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct s_draw_limits
{
	int				start;
	int				end;
}					t_draw_limits;

typedef struct s_color
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_color;

typedef struct s_animation
{
	mlx_texture_t	**frames;
	int				tot_frames;
	int				cur_frame;
	int				playing;
}					t_animation;

typedef struct s_textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
	mlx_texture_t	*door;
}					t_textures;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	int				side;
	int				wall_door;
}					t_ray;

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
	t_animation		f_anim;
	t_animation		lc_anim;
	t_animation		rc_anim;
	char			*path_file;
}					t_game;

/* ========== ERROR ================*/

#define FD "Error | fd"
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

// main.c
void				handle_input(void *param);
void				animations(mlx_key_data_t keydata, void *param);
void				handle_mouse(double xpos, double ypos, void *param);
int					parsing(t_game *game, char **argv);
int					check_fd(int fd);
int					file_order(t_game *game, int fd);

// fc
int					fc_in_game(t_game *game, char **fc);
int					fc_in_game(t_game *game, char **fc);
// texture
int					texture_in_game(t_game *game, char **texture);
int					texture_in_game(t_game *game, char **texture);
// map
int					map_in_game(t_game *game, char **line, int fd, int len);
char				*file_to_tab(int fd, char **texture, char **fc);
// verif map
int					verif_map(char **map);
void				verif_flood(t_game *game);
void				free_texture(char **map, int taille);
int					verif_map(char **map);

// tools:
int					is_number(char c);
int					line_is_space(char *line);
int					check_char(char c);
int					check_fd(int fd);
void				skip_empty_line(char **line, int *fd);
void				len_of_map(t_game *game, char **map);
void				bz(int *tab, int n);
void				free_parsing(t_game *game);

// free.c
void				free_anim(t_animation *anim, int nb_frame_init);
void				free_anims(t_game *game);
void				free_anims_tmp(t_game *game, int nb_anim,
						int nb_frame_init);
void				free_game_tmp(t_game *game, int nb_anim, int nb_frame_init);
void				free_game(t_game *game);
void				exit_game(t_game *game);

// init.c
void				init_game(t_game *game);
void				init_screen(t_game *game);
void				init_ray(t_game *game);

// init_player.c
void				init_player(t_game *game);
void				init_n(t_player *player, int x, int y);
void				init_s(t_player *player, int x, int y);
void				init_w(t_player *player, int x, int y);
void				init_e(t_player *player, int x, int y);

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
void				render_minimap(t_game *game);

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

// minimap.c
void				draw_minimap(t_game *game, t_xy start, int tile_size);
int					is_valid_tile(t_game *game, int map_x, int map_y);
uint32_t			get_tile_color(t_game *game, int map_x, int map_y);
void				draw_tile(t_game *game, t_xy xy, int tile_size,
						uint32_t color);

// door.c
void				open_door(t_game *game);

// knife.c
void				init_knife_animation(t_game *game, t_animation *anim,
						int nb_frames, char *path);
void				draw_animation(t_game *game, t_animation *anim);
void				init_knife_frame(t_game *game, t_animation *anim,
						char *path);
int					verif_255(char *fc[2]);
int					ft_atoi_256(const char *str);
