#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;
	int i;
	int j;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("MAP DOES NOT WORK");
	if (argc != 2)
		ft_error("Wrong number of arguments");
	ft_check_arg(argv[1], map);
	map->contents = ft_get_line(map);
//	map = ft_init_map(map);
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			printf("%c", map->map[i][j]);
			j++;
		}
		i++;
	}
	return 0;
}
