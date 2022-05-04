#include "../so_long.h"

int	ft_end_game(void)
{
	printf("GAME OVER!!!");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_press_key(int key, t_map *map)
{
	if (key == 13)
		ft_player_move_up(map);
	else if (key == 0)
		ft_player_move_left(map);
	else if (key == 1)
		ft_player_move_down(map);
	else if (key == 2)
		ft_player_move_right(map);
	else if (key == 53)
		ft_end_game();
	ft_print_map(map);
	return (0);
}

void	ft_moves(t_map *map)
{
	mlx_hook(map->window, 2, 0, ft_press_key, map);
	mlx_hook(map->window, 17, 0, ft_end_game, map);
	mlx_loop_hook(map->mlx, ft_print_map,map);
}
