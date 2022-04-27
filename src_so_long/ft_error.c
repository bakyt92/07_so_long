#include "../so_long.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}