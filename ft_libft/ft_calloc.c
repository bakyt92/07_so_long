/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:26:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:23:13 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*place;
	unsigned int	total;

	total = count * size;
	place = malloc(total);
	if (place == NULL)
		return (NULL);
	ft_memset(place, 0, total);
	return (place);
}
