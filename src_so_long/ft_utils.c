/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:44:40 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/06 01:19:55 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char 	c;
//	char	*new_line;
	char	*tmp;

	c = '\0';
	line = ft_strdup("");
	while (read(map->fd, &c, 1) > 0)
	{
		tmp = line;
		line = new_ft_strjoin(line, c);
		free(tmp);
	}
	printf("%s", line);
/*
	new_line = ft_strdup("");
	line = ft_strdup("");
	while (line)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_strjoin(new_line, line);
		free(line);
		free(tmp);
	}
	free(line);
	close(map->fd);
	return (new_line);
 */
	return (line);
}

char    *new_ft_strjoin(char const *s1, char s2)
{
	char    *str;
	int     i;
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char) + 1);
	if (!str || !s2)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = s2;
	i++;
	str[i] = '\0';
	return (str);
}
