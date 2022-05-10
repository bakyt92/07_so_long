#include "../so_long.h"

int	ft_animation(t_map *map)
{
	static int coll;

//	printf("COLLECTIBLES_ID = %d \n", coll);
	if (coll < 60)
	{
		ft_print_collectibles(map, coll);
		coll++;
	}
	if (coll == 60)
		coll = 0;
	return (0);
}

void	ft_print_collectibles(t_map *map, int collectibles)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	if (collectibles < 15)
	{
		map->img.col1 = mlx_xpm_file_to_image(map->mlx, COL1, &x, &y);
		map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	}
	else if (collectibles < 30)
	{
		map->img.col1 = map->img.col2;
		map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	}
	else if (collectibles < 45)
	{
		map->img.col1 = map->img.col4;
		map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER1, &x, &y);
	}
	else if (collectibles < 60)
	{
		map->img.col1 = map->img.col4;
		map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER2, &x, &y);
	}
}
