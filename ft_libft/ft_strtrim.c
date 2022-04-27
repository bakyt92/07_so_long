/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:29:50 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:59:08 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != set[j])
		{
			if (set[j] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = (int)ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (s1[i] != set[j])
		{
			if (!set[j])
				return (i);
			j++;
		}
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;
	char	*s_new;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_begin(s1, set) < 0)
		return (ft_strdup(""));
	begin = ft_begin(s1, set);
	end = ft_end(s1, set);
	s_new = (char *) malloc(sizeof(char) * (end - begin + 2));
	if (!s_new)
		return (s_new);
	i = end - begin;
	while (i >= 0)
	{
		s_new[i] = s1[begin + i];
		i--;
	}
	s_new[end - begin + 1] = '\0';
	return (s_new);
}
