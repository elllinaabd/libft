/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:55:43 by radan             #+#    #+#             */
/*   Updated: 2021/10/22 16:55:45 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*arr;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		arr = (char *)malloc(sizeof(char) * (size + 1));
		if (!arr)
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			arr[i++] = s1[j];
		j = -1;
		while (s2[++j])
			arr[i++] = s2[j];
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
