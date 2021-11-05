/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:30 by radan             #+#    #+#             */
/*   Updated: 2021/10/22 16:44:32 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(int n)
{
	int		count;
	long	res;

	res = n;
	count = 1;
	if (res < 0)
	{
		count++;
		res *= (-1);
	}
	while (res >= 10)
	{
		count++;
		res /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	res;
	int		i;

	i = 0;
	array = (char *)malloc(sizeof(char) * check_size(n) + 1);
	if (!array)
		return (NULL);
	if (n < 0)
		array[0] = '-';
	res = n;
	if (res < 0)
		res *= (-1);
	array[check_size(n) - i++] = '\0';
	while (res >= 10)
	{
		array[check_size(n) - i++] = (res % 10) + '0';
		res /= 10;
	}
	array[check_size(n) - i++] = (res % 10) + '0';
	return (array);
}
