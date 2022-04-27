/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:30:50 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:53:28 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	while (--dstsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (count);
}
