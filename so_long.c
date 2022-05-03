/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:43:33 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/03 19:44:47 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("MAP DOES NOT WORK");
	if (argc != 2)
		ft_error("Wrong number of arguments");
	ft_check_arg(argv[1], map);
	map->contents = ft_get_line(map);
	map = ft_init_map(map);
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->length * TILE_Y, map->height
																 * TILE_X, "so_long");
	ft_push_sprites(map);
	ft_print_map(map);
//	ft_moves(map);
	mlx_loop(map->mlx);
	return (0);
}
