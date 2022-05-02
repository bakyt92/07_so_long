#include "so_long.h"

int main(int argc, char **argv)
{
	printf("%s", "checkpoint_1 \n");

	t_map	*map;
	int i;
	int j;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("MAP DOES NOT WORK");
	if (argc != 2)
		ft_error("Wrong number of arguments");
	printf("%s", "checkpoint_2 \n");
	ft_check_arg(argv[1], map);
	printf("%s", "checkpoint_3 \n");
	map->contents = ft_get_line(map);
//	map = ft_init_map(map);
	printf("%s", "checkpoint_4 \n");
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
