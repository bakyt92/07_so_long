#include "../so_long.h"

t_map	*ft_init_map(t_map *map)
{
	int rows;

	rows = 0;
	map->map = ft_split(map->contents, "\n");
	while (map->map[rows])
		rows++;
	map->width = ft_strlen(map->map[0]);
	map->length = rows;
//	map->mlx = mlx_init();
//	map->window = mlx_new_window(map->mlx, map->length * SIZE_X,
//		map->width * SIZE_Y)
}