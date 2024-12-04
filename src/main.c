#include "cub3d.h"

int	main(void)
{
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);

	mlx_loop(mlx);
}

