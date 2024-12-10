#include "cub3d.h"

int	*check_multi_char(int *multi_char, char c)
{
	if (c == 'N')
		multi_char[0]++;
	else if (c == 'S')
		multi_char[1]++;
	else if (c == 'E')
		multi_char[2]++;
	return (multi_char);
}

int	verif_map(char **map)
{
	int	i;
	int	j;
	int	multi_char[2];

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_char(map[i][j]))
				return (0);
			multi_char = check_multi_char(multi_char, map[i][j]);
			j++;
		}
		i++;
	}
	if (multi_char[0] > 1 || multi_char[1] > 1 || multi_char[2] > 1)
		return (0);
	return (1);
}

