/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:29:59 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:57:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (void *)0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (str);
}
