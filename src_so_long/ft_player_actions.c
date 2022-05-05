#include "../so_long.h"

void	ft_move_step(t_map *map, int x, int y)
{
	int i;

	i = 0;
	map->map[map->player_pos.y + y][map->player_pos.x + x] = 'P';
	map->map[map->player_pos.y][map->player_pos.x] = '0';
	map->player_pos.y += y;
	map->player_pos.x += x;
	map->steps++;
	printf("Num of steps: %d\n", map->steps);
	printf("Num of diamonds: %d\n", map->col_num);
	while (map->map[i])
	{
		printf("%s \n", map->map[i]);
		i++;
	}
}

void	ft_player_move_up(t_map *map)
{
	if (map->map[map->player_pos.y - 1][map->player_pos.x] == '0' ||
			map->map[map->player_pos.y - 1][map->player_pos.x] == 'P')
		ft_move_step(map, 0, -1);
	else if (map->map[map->player_pos.y - 1][map->player_pos.x] == 'C')
	{
		ft_move_step(map, 0, -1);
		map->col_num--;
	}
	else if (map->map[map->player_pos.y - 1][map->player_pos.x] == 'E' &&
				map->col_num == 0)
	{
		map->steps++;
		printf("Num of steps: %d\n", map->steps);
		ft_end_game(map);
	}
}

void	ft_player_move_down(t_map *map)
{
	if (map->map[map->player_pos.y + 1][map->player_pos.x] == '0' ||
			map->map[map->player_pos.y + 1][map->player_pos.x] == 'P')
		ft_move_step(map, 0, 1);
	else if (map->map[map->player_pos.y + 1][map->player_pos.x] == 'C')
	{
		ft_move_step(map, 0, 1);
		map->col_num--;
	}
	else if (map->map[map->player_pos.y + 1][map->player_pos.x] == 'E' &&
			 map->col_num == 0)
	{
		map->steps++;
		printf("Num of steps: %d\n", map->steps);
		ft_end_game(map);
	}
}

void	ft_player_move_left(t_map *map)
{
	if (map->map[map->player_pos.y][map->player_pos.x - 1] == '0' ||
			map->map[map->player_pos.y][map->player_pos.x - 1] == 'P')
		ft_move_step(map, -1, 0);
	else if (map->map[map->player_pos.y][map->player_pos.x - 1] == 'C')
	{
		ft_move_step(map, -1, 0);
		map->col_num--;
	}
	else if (map->map[map->player_pos.y][map->player_pos.x - 1] == 'E' &&
			 map->col_num == 0)
	{
		map->steps++;
		printf("Num of steps: %d\n", map->steps);
		ft_end_game(map);
	}
}

void	ft_player_move_right(t_map *map)
{
	if (map->map[map->player_pos.y][map->player_pos.x + 1] == '0' ||
			map->map[map->player_pos.y][map->player_pos.x + 1] == 'P')
		ft_move_step(map, 1, 0);
	else if (map->map[map->player_pos.y][map->player_pos.x + 1] == 'C')
	{
		ft_move_step(map, 1, 0);
		map->col_num--;
	}
	else if (map->map[map->player_pos.y][map->player_pos.x + 1] == 'E' &&
			 map->col_num == 0)
	{
		map->steps++;
		printf("Num of steps: %d\n", map->steps);
		ft_end_game(map);
	}
}