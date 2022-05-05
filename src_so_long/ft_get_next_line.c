/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:54:09 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/05/05 23:54:12 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_line_write(char *line, char *main_str)
{
	int	i;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	else
	{
		line[i] = '\0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_del_one_line(char *main_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	temp = (char *) malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (main_str[i] != '\0')
		temp[j++] = main_str[i++];
	temp[j] = '\0';
	free(main_str);
	return (temp);
}

char	*ft_get_one_line(char *main_str)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line = ft_line_write(line, main_str);
	return (line);
}

char	*ft_read_text(int fd, char *str_main)
{
	ssize_t	byte_read;
	char	buf[BUFFER_SIZE + 1];


	byte_read = 1;
	while (!ft_strchr(str_main, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		printf("%s", "checkpoint_gnl_2.3 \n");
		if (byte_read == -1)
		{
			free(str_main);
			return (NULL);
		}
		buf[byte_read] = '\0';
		str_main = ft_strjoin(str_main, buf);
	}
	return (str_main);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_main;

	printf("%s", "checkpoint_gnl_1.1 \n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str_main = ft_read_text(fd, str_main);
	printf("%s", "checkpoint_gnl_1.2 \n");
	if (!str_main)
		return (NULL);
	line = ft_get_one_line(str_main);
	printf("%s", "checkpoint_gnl_1.3 \n");
	str_main = ft_del_one_line(str_main);
	printf("%s", "checkpoint_gnl_1.4 \n");
	return (line);
}


/*
char	*ft_read(int fd, char *buf, char *str)
{
	ssize_t	byte_was_read;
	char	*s;

	byte_was_read = read(fd, buf, BUFFER_SIZE);
	while (byte_was_read > 0)
	{
		buf[byte_was_read] = '\0';
		if (!str)
			str = ft_strdup("");
		s = ft_strjoin(str, buf);
		free(str);
		str = s;
		if (ft_strchr(buf, '\n'))
			break ;
		byte_was_read = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

static char	*return_line(char **str)
{
	char	*out;
	char	*con;
	size_t	len;

	len = 0;
	out = NULL;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		out = ft_substr(*str, 0, len + 1);
		con = ft_strdup(*str + len + 1);
		free(*str);
		*str = con;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
		return (out);
	}
	out = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (out);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, str);
	free(buf);
	if (!str)
		return (NULL);
	return (return_line(&str));
}
*/