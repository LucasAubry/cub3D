/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:36:36 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 02:37:28 by dalebran         ###   ########.fr       */
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
}					t_game;

/* ========== ERROR ================*/

/* ========== FONCTION ============ */

// main.c
void				handle_input(void *param);
void				animations(mlx_key_data_t keydata, void *param);
void				handle_mouse(double xpos, double ypos, void *param);

// free.c
void				free_game(t_game *game);
void				exit_game(t_game *game);

// init.c
t_game				*init_game(void);
void				init_map(t_game *game);
void				init_textures(t_game *game);
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
void				init_knife_animation(t_animation *anim, int nb_frames,
						char *path);
void				draw_animation(t_game *game, t_animation *anim);
void				init_knife_frame(t_animation *anim, char *path);