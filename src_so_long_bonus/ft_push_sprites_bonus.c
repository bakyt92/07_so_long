/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:44:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/06 02:05:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_push_sprites(t_map *map)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, EXIT1, &x, &y);
	map->img.col1 = mlx_xpm_file_to_image(map->mlx, COL1, &x, &y);
	map->img.col2 = mlx_xpm_file_to_image(map->mlx, COL2, &x, &y);
	map->img.col3 = mlx_xpm_file_to_image(map->mlx, COL3, &x, &y);
	map->img.col4 = mlx_xpm_file_to_image(map->mlx, COL4, &x, &y);
	if (!map->img.wall || !map->img.floor || !map->img.player || !map->img.exit
		|| !map->img.col1 || !map->img.col2 || !map->img.col3 || !map->img.col4)
		ft_error("Picture error");
}
