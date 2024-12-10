#include "cub3d.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(char	c)
{
	if (c != 'N' || c != 'S' || c != 'E' || c != 0 || c != 1)
		return (0);
	return (1);
}

int	check_fd(int fd)
{
	if (fd == -1)
		return (0);
	else
		return (1);
}

char	*skip_empty_line(char *line, int *fd)
{
	while (line != NULL && !line_is_space(line))
	{
		line = ft_get_next_line(*fd);
	}
	return (line);
}
