#include "cub3d.h"

int	put_in_game(char *line, char **texture, char **fc, int index)
{
	if (index >= 0 && index <= 3)
		texture[index] = line;
	else if (index == 4 || index == 5)
		fc[index - 4] = line;
	return (1);
}


int	check_id(char *line, char *id, char **texture, char **fc, int *verif)
{
	if (!ft_strcmp(id, "NO"))
		*verif += put_in_game(line, texture, fc, 0);
	else if (!ft_strcmp(id, "SO"))
		*verif += put_in_game(line, texture, fc, 1);
	else if (!ft_strcmp(id, "WE"))
		*verif += put_in_game(line, texture, fc, 2);
	else if (!ft_strcmp(id, "EA"))
		*verif += put_in_game(line, texture, fc, 3);
	else if (!ft_strcmp(id, "F"))
		*verif += put_in_game(line, texture, fc, 4);
	else if (!ft_strcmp(id, "C"))
		*verif += put_in_game(line, texture, fc, 5);
	else if (!ft_strcmp(id, "\n"))
		return (0);
	return (1);
}

int	add_in_tab(char *line, char **texture, char **fc, int *verif)
{
	char			**id;
	static int		i = 0;

	id = ft_split(line, ' ');
	if (id == NULL)
		i += 0;
	else if (check_id(line, *id, texture, fc, verif) == 1)
		i += 1;
	if (i > 6)
		return (0);
	else if (i == 6)
		return (2);
	return (1);
}

char	*file_to_tab(int fd, char **texture, char **fc)
{
	int		i;
	char	*trim_line;
	char	*line;
	int		verif;

	i = 0;
	verif = 0;
	line = ft_get_next_line(fd);
	line = skip_empty_line(line, &fd);
	while (line != NULL)
	{
		trim_line = ft_strtrim(line, " ");
		line = ft_get_next_line(fd);
		i = add_in_tab(trim_line, texture, fc, &verif);
		if (i == 0)
		{
			printf("error file not gooood");
			return (NULL);
		}
		else if (verif < 6 && i == 2)
		{
			printf("Error need all arguments");
			return (NULL);
		}
		else if (i == 2)
			break;
	}
	return (line);
}
