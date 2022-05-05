/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:44:40 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/06 02:04:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_arg(char *str, t_map *map)
{
	int	str_len;

	str_len = 0;
	map->fd = open(str, O_RDONLY);
	if (map->fd < 0)
		ft_error("FD error\n");
	if (ft_strrchr(str, '/') && ft_strlen(ft_strrchr(str, '/')) <= 5)
		ft_error("Thr file is not a map\n");
	str_len = ft_strlen(str);
	if (ft_strncmp(str + str_len - 4, ".ber", 4))
		ft_error("The file is not '.ber' format\n");
	if (open(str, O_DIRECTORY) > 0)
		ft_error("It is directory\n");
}

char	*ft_get_line(t_map *map)
{
	char	*line;
	char	c;
	char	*tmp;

	c = '\0';
	line = ft_strdup("");
	while (read(map->fd, &c, 1) > 0)
	{
		tmp = line;
		line = ft_nouvel_strjoin(line, c);
		free(tmp);
	}
	return (line);
}

char	*ft_nouvel_strjoin(char const *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!str || !c)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	return (str);
}
