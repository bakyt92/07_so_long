#include "../so_long.h"

void	ft_push_sprites(t_map *map)
{
	int	x;
	int y;

	x = 50;
	y = 50;
	printf("%s", "checkpoint_sprites.1 \n");
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	printf("%s", "checkpoint_sprites.2 \n");
	map->img.floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, EXIT1, &x, &y);
	map->img.col1 = mlx_xpm_file_to_image(map->mlx, COL1, &x, &y);
//	map->img.col2 = mlx_png_file_to_image(map->mlx, COL2, &x, &y);
	printf("%s", "checkpoint_sprites.3 \n");
	if (!map->img.wall || !map->img.floor || !map->img.player || !map->img.exit
			|| !map->img.col1)
		ft_error("Picture error");
//	map->img.col1 = map->img.col2;
}