/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:21:26 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 16:33:17 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_anims(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->f_anim.tot_frames)
		mlx_delete_texture(game->f_anim.frames[i++]);
	free(game->f_anim.frames);
	i = 0;
	while (i < game->lc_anim.tot_frames)
		mlx_delete_texture(game->lc_anim.frames[i++]);
	free(game->lc_anim.frames);
	i = 0;
	while (i < game->rc_anim.tot_frames)
		mlx_delete_texture(game->rc_anim.frames[i++]);
	free(game->rc_anim.frames);
}

void	free_anims_tmp(t_game *game, int nb_anim, int nb_frame_init)
{
	if (nb_anim == 0)
	{
		free_anim(&game->rc_anim, nb_frame_init);
		return ;
	}
	else
		free_anim(&game->rc_anim, game->rc_anim.tot_frames);
	if (nb_anim == 1)
	{
		free_anim(&game->lc_anim, nb_frame_init);
		return ;
	}
	else
		free_anim(&game->lc_anim, game->lc_anim.tot_frames);
	if (nb_anim == 2)
	{
		free_anim(&game->f_anim, nb_frame_init);
		return ;
	}
	else
		free_anim(&game->f_anim, game->f_anim.tot_frames);
}

void	free_anim(t_animation *anim, int nb_frame_init)
{
	int	i;

	i = 0;
	while (i < nb_frame_init)
		mlx_delete_texture(anim->frames[i++]);
	free(anim->frames);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->path_file);
	free_anims(game);
	mlx_delete_texture(game->textures.n);
	mlx_delete_texture(game->textures.s);
	mlx_delete_texture(game->textures.w);
	mlx_delete_texture(game->textures.e);
	mlx_delete_texture(game->textures.door);
}

void	free_game_tmp(t_game *game, int nb_anim, int nb_frame_init)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->path_file);
	free_anims_tmp(game, nb_anim, nb_frame_init);
	mlx_delete_texture(game->textures.n);
	mlx_delete_texture(game->textures.s);
	mlx_delete_texture(game->textures.w);
	mlx_delete_texture(game->textures.e);
	mlx_delete_texture(game->textures.door);
}
