#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("MAP DOES NOT WORK");
	if (argc != 2)
		ft_error("Wrong number of arguments");
//	printf("%s", "checkpoint_2 \n");
	ft_check_arg(argv[1], map);
//	printf("%s", "checkpoint_3 \n");
	map->contents = ft_get_line(map);
	map = ft_init_map(map);
	printf("%s", "checkpoint_3.1 \n");
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->width * TILE_Y, map->length *
																TILE_X,"so_long");
	ft_push_sprites(map);
	printf("%s", "checkpoint_3.2 \n");
	ft_push_image(map);
	return 0;
}
