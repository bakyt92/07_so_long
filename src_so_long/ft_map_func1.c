#include "../so_long.h"

t_map	*ft_init_map(t_map *map)
{
	int rows;

	rows = 0;
	map->map = ft_split(map->contents, '\n');
	while (map->map[rows])
		rows++;
	map->length = ft_strlen(map->map[0]);
	map->height = rows;
	ft_check_map(map);
	map->col_num = 0;
	map->steps = 0;
	return(map);
}

void	ft_push_image(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img.wall,
				j * TILE_X,i * TILE_Y);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->img.floor,
				j * TILE_X,i * TILE_Y);
	else if (map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->window, map->img.floor,
				j * TILE_X,i * TILE_Y);
		map->player_pos.x = j;
		map->player_pos.y = i;
	}
	else if (map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->window, map->img.floor,
								j * TILE_X,i * TILE_Y);
		mlx_put_image_to_window(map->mlx, map->window, map->img.col1,
				j * TILE_X,i * TILE_Y);
		map->col_num++;
	}
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img.exit,
				j * TILE_X,i * TILE_Y);
}

void	ft_push_player(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->window, map->img.player,
				 map->player_pos.x * TILE_X,map->player_pos.y * TILE_Y);
}

int	ft_print_map(t_map *map)
{
	int	i;
	int j;

	i = 0;
//	mlx_hook(map->window, 17, 0, game_over, 0);
//	map->image1 = mlx_new_image(map->mlx, 60, 40);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_push_image(map, i, j);
			j++;
		}
		i++;
	}
	ft_push_player(map);
	return (0);
}