#include "../so_long.h"

void	ft_check_arg(char *str, t_map *map)
{
	int	str_len;

	str_len = 0;
	map->fd = open(str, O_RDONLY);
	if (map->fd < 0)
		ft_error("FD error");
	if (ft_strrchr(str, '/') &&
			ft_strlen(ft_strrchr(str, '/')) <= 5)
		ft_error("Thr file is not a map");
	str_len = ft_strlen(str);
	if (ft_strncmp(str + str_len - 4, ".ber", 4))
		ft_error("The file is not '.ber' format");
	if (open(str, O_DIRECTORY) > 0)
		ft_error("It is directory");

}

char	*ft_get_line(t_map *map)
{
	char	*line;
	char	*new_line;
	char	*tmp;

	new_line = ft_strdup("");
	line = ft_strdup("");
//	printf("%s", "checkpoint_gnl_1 \n");
	while (line)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
//		printf("%s \n", line);
		tmp = new_line;
		new_line = ft_strjoin(new_line, line);
//		printf("%s", "checkpoint_gnl_3 \n");
		free(line);
		free(tmp);
	}
	close(map->fd);
//	printf("%s", new_line);
	return (new_line);
}

