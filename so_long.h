#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./ft_libft/libft.h"
#include "./ft_get_next_line/get_next_line.h"
#include "./minilibx_macos/mlx.h"

# define SIZE_X 48
# define SIZE_Y 48


typedef struct s_map
{
	char	**map;
	char	*contents;
	int		fd;
	int 	width;
	int 	length;
	void	*mlx;
} t_map;

void	ft_error(char *str);
char	*ft_get_line(t_map *map);
void	ft_check_arg(char *str, t_map *map);
t_map	*ft_init_map(t_map *map);

#endif
