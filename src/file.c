#include "cub3d.h"

char	**path_to_texture(char **texture)
{
	char	*path;
	char	*new_texture;
	int		i;

	i = 0;
	while (i != 4)
	{
		path = ft_strstr(texture[i], "./");
		path = ft_strtrim(path, "\n");
		if (path)
		{
			new_texture = ft_strdup(path);
			free(texture[i]);
			texture[i] = ft_strdup(new_texture);
			free(new_texture);
		}
		i++;
	}
	return (texture);
}

int	texture_in_game(t_game *game, char **texture)
{
	texture = path_to_texture(texture);
    game->textures.n = mlx_load_png(texture[0]);
    game->textures.s = mlx_load_png(texture[1]);
    game->textures.e = mlx_load_png(texture[2]);
    game->textures.w = mlx_load_png(texture[3]);	
	if (game->textures.n == NULL || game->textures.s == NULL ||
			game->textures.e == NULL || game->textures.w == NULL)
		return (0);
	return (1);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	fc_to_tab(uint8_t *floor_cel, char **fc, int i)
{
	char	*rgb;
	char	color[16];
	int		j;
	int		k;

	k = 0;
	rgb = ft_strchr(fc[i], ' ');
	while (*rgb != '\0')	
	{
		j = 0;
		while (*rgb == ' ' || *rgb == '\t')	
			rgb++;
		ft_bzero(color, ft_strlen(rgb) + 1);
		while (is_number(*rgb))
			color[j++] = *rgb++;
		if (*rgb != '\0' && *rgb != ',' && *rgb != ' ' && *rgb != '\t')
			return (0);
		floor_cel[k++] = (uint8_t)ft_atoi(color);
		if (*rgb)
			rgb++;
	}
	return (1);
}

int	verif_comma(char **fc)
{
	int	i;
	int	v;
	int	v1;

	i = 0;
	v = 0;
	v1 = 0;
	while (fc[0][i] && fc[1][i])
	{
		if (fc[0][i] == ',')
			v++;
		if (fc[1][i] == ',')
			v1++;
		i++;
	}
	if (v > 2 || v1 > 2)
		return (0);
	return (1);
}

int	select_fc(uint8_t *floor, uint8_t *ceiling, char **fc)
{
	fc[0] = ft_strtrim(fc[0], "\n");
	fc[1] = ft_strtrim(fc[1], "\n");
	if (!verif_comma(fc))
	{
		printf("%s\n", COMMA);
		return (0);
	}
	if (!fc_to_tab(floor, fc, 0) || !fc_to_tab(ceiling, fc, 1))
	{
		printf("%s\n", CHAR_RGB);
		return (0);
	}
	return (1);
}

int	verif_255(t_game *game)
{
	if (game->floor_color.r <= 255 && game->floor_color.g <= 255 &&
			game->floor_color.b <= 255 && game->ceiling_color.r <= 255 &&
			game->ceiling_color.g <= 255 && game->ceiling_color.b <= 255)
		return (1);
	return (0);
}

int	fc_in_game(t_game *game, char **fc)
{
	uint8_t	floor[3];
	uint8_t	ceiling[3];

	if (!select_fc(floor, ceiling, fc))
		return (0);
	game->floor_color.r = floor[0];
	game->floor_color.g = floor[1];
	game->floor_color.b = floor[2];
	game->ceiling_color.r = ceiling[0];
	game->ceiling_color.g = ceiling[1];
	game->ceiling_color.b = ceiling[2];
	if (!verif_255(game))
	{
		printf("%s\n", ERROR_255);
		return (0);
	}
	return (1);
}

int	verif_file_order(t_game *game, int fd)
{
	char	*line;
	int		i;
	char	*texture[4];
	char	*fc[2];

	i = 0;
	line = NULL;
	line = skip_empty_line(line, &fd);
	while (i != 4)
	{
		if (i != 0)
			line = ft_get_next_line(fd);
		line = skip_empty_line(line, &fd);
		texture[i] = line;
		i++;
	}
	i = 0;
	skip_empty_line(line, &fd);
	while (i != 2)
	{
		line = ft_get_next_line(fd);
		line = skip_empty_line(line, &fd);
		fc[i] = line;
		i++;
	}
	if (!verif_texture_fc(texture, fc))
		return (0);
	if (!texture_in_game(game, texture))
		return (0);
	if (!fc_in_game(game, fc))
		return (0);
	return (1);
}
