#include "so_long.h"

int main(int argc, char **argv)
{
	ft_isdigit(5);

	int		fd;
	t_map	*map;

	if (argc != 2)
		ft_error("Wrong number of arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("FD error");
//	ft_check_arg(argv[1]);
//	map = ft_parsing(argv);

	return 0;
}
