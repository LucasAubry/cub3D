/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:15:17 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/11 02:34:34 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*select_texture(t_game *game)
{
	if (game->ray.wall_door == 1)
		return (game->textures.door);
	else if (game->ray.side == 0 && game->ray.dir_x > 0)
		return (game->textures.e);
	else if (game->ray.side == 0 && game->ray.dir_x < 0)
		return (game->textures.w);
	else if (game->ray.side == 1 && game->ray.dir_y > 0)
		return (game->textures.s);
	else
		return (game->textures.n);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t	color;
	int			tex_offset;

	if (!texture)
		return (0xFFFFFFFF);
	tex_offset = (tex_y * texture->width + tex_x) * 4;
	color = (texture->pixels[tex_offset] << 24)
		| (texture->pixels[tex_offset + 1] << 16)
		| (texture->pixels[tex_offset + 2] << 8)
		| (texture->pixels[tex_offset + 3]);
	return (color);
}

uint32_t	rgb_to_rgba(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
