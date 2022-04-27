/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:28:59 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:32:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symbol;

	str = (unsigned char *)arr;
	symbol = (unsigned char)c;
	while (n--)
	{
		if (*str == symbol)
			return ((void *)str);
		str++;
	}
	return ((void *)0);
}
