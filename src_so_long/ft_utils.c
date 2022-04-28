#include "../so_long.h"

void	ft_check_arg(char *str, t_map *map)
{
	map->fd = open(str, O_RDONLY);
	if (map->fd < 0)
		ft_error("FD error");
	if (ft_strchr(str, '/'))
		ft_error("FD error");
}