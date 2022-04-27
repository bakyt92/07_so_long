/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:30:54 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:52:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	d = (char *)src;
	while (dst[a] != '\0' && dstsize > a)
		++a;
	while (src[b] != '\0' && (a + b + 1) < dstsize)
	{
		dst[a + b] = src[b];
		++b;
	}
	if (a < dstsize)
	{
		dst[a + b] = '\0';
		return (a + ft_strlen(d));
	}
	else
		return (dstsize + ft_strlen(src));
}
