/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:31:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:40:05 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_words_write(const char *s, char **arr, char c, int num_words)
{
	int	i;
	int	j;
	int	word_len;

	j = 0;
	i = 0;
	while (j < num_words)
	{
		while (s[i] == c)
			i++;
		word_len = 0;
		while (s[i + word_len] != c && s[i + word_len])
			word_len++;
		arr[j] = ft_substr(s, i, word_len);
		if (!arr[j] && j != 0)
		{
			while (--j >= 0)
				free(arr[j]);
			free(arr);
		}
		i += word_len;
		j++;
	}
	return (arr);
}

static int	ft_num_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || \
			(s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	num_words = ft_num_words((char *)s, c);
	arr = (char **)ft_calloc((num_words + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_words_write(s, arr, c, num_words);
	return (arr);
}
