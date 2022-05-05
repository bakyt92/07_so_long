/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:22 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/12/26 20:02:38 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

#include "get_next_line.h"
#include <stdio.h>

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

	printf("%s", "checkpoint_gnl_2.1 \n");
	printf("%s, %s", ft_strchr("BAKYT", 'A'), "NEWLINE \n");
	printf("FD IS %d", fd);
	printf("%s", "checkpoint_gnl_2.1.1 \n");
	byte_read = 1;
	while (!ft_strchr(str_main, '\n') && byte_read != 0)
	{
		printf("%s", "checkpoint_gnl_2.2 \n");
		byte_read = read(fd, buf, BUFFER_SIZE);
		printf("%s", "checkpoint_gnl_2.3 \n");
		if (byte_read == -1)
		{
			free(str_main);
			return (NULL);
		}
		buf[byte_read] = '\0';
		str_main = ft_gnl_strjoin(str_main, buf);
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
int	main (void)
{
//	int fd;
//	char *line;
//
//	line = "";
//	fd = open("test_text.txt", O_RDONLY);
//	while (line)
//	{
////		printf("\t iter = %d \t", iter);
//		line = get_next_line(fd);
//		if (!line)
//			break;
//		printf("%s", line);
//		free (line);
//	}
//
//	close(fd);
//	free (line);
//	while(1)
//		;

	return (0);
}
*/

*/