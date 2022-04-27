/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:31:11 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:48:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	while (*s != (unsigned char)ch)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
