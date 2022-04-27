/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:26:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:22:22 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*l;
	size_t			x;

	l = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		*l = '\0';
		l++;
		x++;
	}
}
