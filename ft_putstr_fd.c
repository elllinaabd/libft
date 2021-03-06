/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:47:07 by radan             #+#    #+#             */
/*   Updated: 2021/10/22 16:47:10 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	int	i;

	i = 0;
	if (s && fd)
	{	
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
