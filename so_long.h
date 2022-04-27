#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./ft_libft/libft.h"

typedef struct s_map
{
	char	**map;

} t_map;

void	ft_error(char *str);
void	ft_check_arg(char *str);

#endif
