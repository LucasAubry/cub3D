#include "cub3d.h"

//void	file_in_tab(t_game *game, int fd)
//{
//	char	*line;
//
//	while (line)
//	{
//		line = get_next_line(fd);
//		game->map[i] = ft_strtrim(line, "\n");
//		free(line);
//		i++;
//	}
//	game->map[i] = NULL;
//	close(fd);
//}



int	file(char **argv)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
	{
		ft_error("%s\n", NOT_CUB);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			point++;
		i++;
	}
	if (point > 1)
	{
		ft_error("%s\n", FILE_NOT_CORRECT);
		return (0);
	}
	return (1);
}

int	map(t_game *game, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	game->path_file = ft_strdup(argv[1]);
	if (!check_fd(fd))
	{
		ft_error("%s\n", FD);
		return (0);
	}
	if (!file_order(game, fd))
	{
		ft_error("%s\n", FILES);
		return (0);
	}
	printf("tout bon ");


//	file_in_tab(game, fd);
//	if (!verif_map(game->map))
//	{
//		ft_error("%s\n", BAD_CHAR);
//		return (0);
//	}
//	if (!border_wall(game->map))
//	{
//		ft_error("%s\n", BORDER_WALL);
//		return (0);
//	}
	return (1);
}

int	parsing(t_game *game, char **argv)
{
	if (!file(argv))
	{
		printf("FILE\n");
		return (0);
	}
	if (!map(game, argv))
	{
		printf("MAP\n");
		return (0);
	}
	printf("tout bon parsig\n");
	return (1);
}

/*============TODO FOR PARSING============

 - si la map est fermer par des murs
 - si la map mis a part la description de la map map chaque type delement peut separer pas des lignes vides
 -sauf pour la map les info de chaque element peuvent etre separer par plusieur espace
 

fichier valide :


 NO ./asset/W1.xpm
SO ./asset/W2.xpm
WE ./asset/W3.xpm
EA ./asset/W4.xpm
D ./asset/door.xpm
S0 ./asset/sprite0.xpm
S1 ./asset/sprite1.xpm
S2 ./asset/sprite2.xpm
S3 ./asset/sprite3.xpm
S4 ./asset/sprite4.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000101
        10110000011100000000X0011
        1001000000P00000000000001
111111111011000001110000000000001
1000000000110000011101P111P111111
11110111111111011100000010001
1111P111111111011P01010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111


regarde sujet pour suite
*/
