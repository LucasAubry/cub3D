/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knife.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:50:34 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/10 14:19:59 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initKnifeAnimation(t_game *game)
{
	char	*path;
	int		i;
	char	*c;
	char	*extension;

	game->k_anim.tot_frames = 178;
	game->k_anim.frames = malloc(sizeof(mlx_texture_t *) * 178);
	game->k_anim.cur_frame = 0;
	game->k_anim.playing = 0;
	game->k_anim.frame_delay = 50;
	game->k_anim.last_update = 0;
	i = 0;
	while (i < 178)
	{
		path = "anim/knife_v2/frame";
		c = ft_itoa(i);
		extension = ".png";
		path = ft_strjoin(path, c);
		path = clean_join(path, extension);
		game->k_anim.frames[i] = mlx_load_png(path);
		if (!game->k_anim.frames[i])
		{
			ft_printf("Error loading frame %d\n", i);
			exit(EXIT_FAILURE);
		}
		free(c);
		i++;
	}
}

void	draw_animation(t_game *game)
{
	int				screen_x;
	int				screen_y;
	int				x;
	int				y;
	mlx_texture_t	*act_frame;
	uint32_t		color;
	uint8_t			*pix;

	if (game->k_anim.cur_frame == 177)
	{
		game->k_anim.playing = 0;
		game->k_anim.cur_frame = 0;
	}
	if (game->k_anim.playing == 1)
	{
		game->k_anim.cur_frame++;
	}
	act_frame = game->k_anim.frames[game->k_anim.cur_frame];
	if (!act_frame)
		return ;
	screen_x = (WIDTH - act_frame->width) / 2;
	screen_y = HEIGHT - act_frame->height;
	y = 0;
	while (y < (int)act_frame->height)
	{
		x = 0;
		while (x < (int)act_frame->width)
		{
			pix = &act_frame->pixels[(y * act_frame->width + x) * 4];
			color = (pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8) | pix[3];
			if ((color >> 24) != 0)
			{
				mlx_put_pixel(game->screen, screen_x + x, screen_y + y, color);
			}
			x++;
		}
		y++;
	}
}

