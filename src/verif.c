#include "cub3d.h"

int	put_in_game(char *line, char **texture, char **fc, int index)
{
	if (index >= 0 && index <= 3)
		texture[index] = line;
	else if (index == 4 || index == 5)
		fc[index - 4] = line;
	return (1);
}


int	check_id(char *line, char *id, char **texture, char **fc)
{
	int	i;

	i = 0;
	if (!ft_strcmp(id, "NO"))
		put_in_game(line, texture, fc, 0);
	else if (!ft_strcmp(id, "SO"))
		put_in_game(line, texture, fc, 1);
	else if (!ft_strcmp(id, "WE"))
		put_in_game(line, texture, fc, 2);
	else if (!ft_strcmp(id, "EA"))
		put_in_game(line, texture, fc, 3);
	else if (!ft_strcmp(id, "F"))
		put_in_game(line, texture, fc, 4);
	else if (!ft_strcmp(id, "C"))
		put_in_game(line, texture, fc, 5);
	else if (!ft_strcmp(id, "\n"))
		return (0);
	return (1);
}

int	add_in_tab(char *line, char **texture, char **fc)
{
	char			**id;
	static int		i = 0;

	id = ft_split(line, ' ');
	if (id == NULL)
		i += 0;
	else if (check_id(line, *id, texture, fc) == 1)
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

	i = 0;
	line = ft_get_next_line(fd);
	line = skip_empty_line(line, &fd);
	while (line != NULL)
	{
		trim_line = ft_strtrim(line, " ");
		line = ft_get_next_line(fd);
		i = add_in_tab(trim_line, texture, fc);
		if (i == 0)
		{
			printf("error file not gooood");
			return (0);
		}
		else if (i == 2)
			break;
	}
	return (line);
}


//int	*check_multi_char(int *multi_char, char c)
//{
//	if (c == 'N')
//		multi_char[0]++;
//	else if (c == 'S')	
//		multi_char[1]++;
//	else if (c == 'E')
//		multi_char[2]++;
//	return (multi_char);
//}
//
//int	verif_map(char **map)
//{
//	int	i;
//	int	j;
//	int	multi_char[2];
//
//	i = 0;
//	while (map[i])
//	{
//		j = 0;
//		while (map[i][j])
//		{
//			if (check_char(map[i][j]))
//				return (0);
//			multi_char = check_multi_char(multi_char, map[i][j]);
//			j++;
//		}
//		i++;
//	}
//	if (multi_char[0] > 1 || multi_char[1] > 1 || multi_char[2] > 1)
//		return (0);
//	return (1);
//}





