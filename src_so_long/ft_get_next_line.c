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
