/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:54:24 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/06 02:02:58 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_symbols(t_map *map, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(str, map->map[i][j]))
				ft_error("There are non-allowed symbols\n");
			j++;
		}
		i++;
	}
}

void	ft_check_len(t_map *map)
{
	size_t	len;
	int		rows;

	len = ft_strlen(map->map[0]);
	rows = 1;
	while (map->map[rows])
	{
		if (len != ft_strlen(map->map[rows]))
			ft_error("Map is not rectangular\n");
		rows++;
	}
}

void	ft_check_walls(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			ft_error("The map is not surrounded by walls\n");
		j++;
	}
	while (map->map[i])
	{
		if (map->map[i][0] == '1' && map->map[i][map->length - 1] == '1')
			i++;
		else
			ft_error("The map is not surrounded by walls\n");
	}
	j = 0;
	while (map->map[map->height - 1][j])
	{
		if (map->map[map->height - 1][j] != '1')
			ft_error("The map is not surrounded by walls\n");
		j++;
	}
}

void	ft_check_pce(t_map *map, int p, int c, int e)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				c++;
			else if (map->map[i][j] == 'P')
			{
				p++;
				map->player_pos.x = j;
				map->player_pos.y = i;
			}
			else if (map->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (c < 1 || p < 1 || e < 1)
		ft_error("Map does not contain player, collectibles or exit\n");
}

void	ft_check_map(t_map *map)
{
	ft_check_len(map);
	ft_check_walls(map);
	ft_check_pce(map, 0, 0, 0);
	ft_check_symbols(map, "01PCE");
}
