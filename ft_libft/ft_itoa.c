/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:52:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:27:47 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert_itoa(int n, int i, char *res, int znak)
{
	while (--i >= 0)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (znak == -1)
		res[0] = '-';
	return (res);
}

static int	numbers(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		znak;

	znak = 1;
	res = NULL;
	i = numbers(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (res);
	res[i] = '\0';
	if (n < 0)
	{
		n *= -1;
		znak = -1;
	}
	res = ft_convert_itoa (n, i, res, znak);
	return (res);
}
