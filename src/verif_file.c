#include "cub3d.h"

int	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

char	*skip_empty_line(char *line, int *fd)
{
	while (!line || !line_is_space(line))
		line = ft_get_next_line(*fd);
	return (line);
}

int	verif_texture_fc(char	**texture, char **fc)
{
	if (ft_strncmp(texture[0], "NO ", 3) == 0 &&
		ft_strncmp(texture[1], "SO ", 3) == 0 &&
		ft_strncmp(texture[2], "WE ", 3) == 0 &&
		ft_strncmp(texture[3], "EA ", 3) == 0 &&
		ft_strncmp(fc[0], "F ", 2) == 0 &&
		ft_strncmp(fc[1], "C ", 2) == 0)
		return (1);
	printf("verif_texture errro");
	return (0);
}

