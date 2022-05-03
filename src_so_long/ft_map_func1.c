#include "../so_long.h"

t_map	*ft_init_map(t_map *map)
{
	int rows;

	rows = 0;
	map->map = ft_split(map->contents, '\n');
	while (map->map[rows])
		rows++;
	map->width = ft_strlen(map->map[0]);
	map->length = rows;
	ft_check_map(map);
	map->col_num = 0;
	map->steps = 0;
	return(map);
}

static int 	game_over(void)
{
	printf("%s", "GAME_OVER");
	exit(0);
	return (0);
}

void	ft_push_image(t_map *map)
{
	int i;

	i = 0;
	mlx_hook(map->window, 17, 0, game_over, 0);
//	map->image1 = mlx_new_image(map->mlx, 60, 40);
	mlx_put_image_to_window(map->mlx, map->window, map->img.wall, i, i);
	mlx_loop(map->mlx);
}