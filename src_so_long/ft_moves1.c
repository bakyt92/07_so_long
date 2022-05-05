/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:45:06 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/05 23:45:08 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_end_game(t_map *map)
{
	int i;

	i = 0;
	printf("GAME OVER!!!");
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	free(&map->player_pos);
	free(&map->img);
	free(map);
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
		ft_end_game(map);
	ft_print_map(map);
	return (0);
}

void	ft_moves(t_map *map)
{
	mlx_hook(map->window, 2, 0, ft_press_key, map);
	mlx_hook(map->window, 17, 0, ft_end_game, map);
	mlx_loop_hook(map->mlx, ft_print_map,map);
}
