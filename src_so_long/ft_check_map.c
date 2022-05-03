#include "../so_long.h"

void	ft_check_symbols(t_map *map, char *str)
{
	int	i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(str, map->map[i][j]))
				ft_error("There are non-allowed symbols");
			j++;
		}
		i++;
	}
}

void	ft_check_len(t_map *map)
{
	size_t len;
	int	rows;

	len = ft_strlen(map->map[0]);
	rows = 1;
	while (map->map[rows])
	{
		if (len != ft_strlen(map->map[rows]))
			ft_error("Map is not rectangular");
		rows++;
	}
}

void	ft_check_walls(t_map *map)
{
	char	walls;
	int 	i;
	int 	j;

	walls = '1';
	i = 0;
	j = 0;
	printf("%s", "checkpoint_walls_0 \n");
	while (map->map[i][j])
	{
		if (map->map[i][j] != walls)
			ft_error("The map is not surrounded by walls");
		j++;
	}
	printf("%s", "checkpoint_walls_1 \n");
	while (map->map[i])
	{
		if (map->map[i][0] == walls && map->map[i][map->width - 1] == walls)
			i++;
		else
			ft_error("The map is not surrounded by walls");
	}
	j = 0;
	printf("%s", "checkpoint_walls_2 \n");
	while (map->map[map->length - 1][j])
	{
		if (map->map[map->length - 1][j] != walls)
			ft_error("The map is not surrounded by walls");
		j++;
	}
	printf("%s", "checkpoint_walls_3 \n");
}

void	ft_check_pce(t_map *map, int p, int c, int e)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				c++;
			else if (map->map[i][j] == 'P')
				p++;
			else if (map->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (c < 1 || p < 1 || e < 1)
		ft_error("Map does not contain player, collectibles or exit");
}

void	ft_check_map(t_map *map)
{
	ft_check_len(map);
	ft_check_walls(map);
	ft_check_pce(map, 0, 0, 0);
	ft_check_symbols(map, "01PCE");
}

