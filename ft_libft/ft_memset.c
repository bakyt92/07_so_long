/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:31:55 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:34:53 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*l;
	size_t			x;

	l = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		*l = c;
		l++;
		x++;
	}
	return (s);
}
