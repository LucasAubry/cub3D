/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knife.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:50:34 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/12 05:33:55 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_knife_animation(t_game *game, t_animation *anim, int nb_frames,
		char *path)
{
	anim->tot_frames = nb_frames;
	anim->frames = malloc(sizeof(mlx_texture_t *) * nb_frames);
	anim->cur_frame = 0;
	anim->playing = 0;
	init_knife_frame(game, anim, path);
}

void	init_knife_frame(t_game *game, t_animation *anim, char *path)
{
	int			i;
	char		*c;
	char		*extension;
	char		*act_path;
	static int	nb_anim_init = 0;

	i = 0;
	while (i < anim->tot_frames)
	{
		c = ft_itoa(i);
		extension = ".png";
		act_path = ft_strjoin(path, c);
		act_path = clean_join(act_path, extension);
		anim->frames[i] = mlx_load_png(act_path);
		if (!anim->frames[i])
		{
			(free(c), free(act_path), free_game_tmp(game, nb_anim_init, i));
			free(game);
			exit(EXIT_FAILURE);
		}
		free(c);
		free(act_path);
		i++;
	}
	nb_anim_init++;
}

void	update_animation_state(t_animation *anim)
{
	if (anim->cur_frame == anim->tot_frames - 1)
	{
		anim->playing = 0;
		anim->cur_frame = 0;
	}
	else if (anim->playing == 1)
	{
		anim->cur_frame++;
	}
}

void	draw_animation_frame(t_game *game, mlx_texture_t *frame, int screen_x,
		int screen_y)
{
	int			x;
	int			y;
	uint32_t	color;
	uint8_t		*pix;

	y = 0;
	while (y < (int)frame->height)
	{
		x = 0;
		while (x < (int)frame->width)
		{
			pix = &frame->pixels[(y * frame->width + x) * 4];
			color = (pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8) | pix[3];
			if ((color >> 24) != 0)
				mlx_put_pixel(game->screen, screen_x + x, screen_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_animation(t_game *game, t_animation *anim)
{
	mlx_texture_t	*act_frame;
	int				screen_x;
	int				screen_y;

	update_animation_state(anim);
	act_frame = anim->frames[anim->cur_frame];
	screen_x = (WIDTH - act_frame->width) / 2;
	screen_y = HEIGHT - act_frame->height;
	draw_animation_frame(game, act_frame, screen_x, screen_y);
}
