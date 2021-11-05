/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:38:46 by radan             #+#    #+#             */
/*   Updated: 2021/10/22 16:38:48 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

static	char	*put_word(char *str, char c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = 0;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

static int	free_arr(char **array, int i)
{
	while (i > 0)
		free(array[i--]);
	free(array[i]);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		array[i] = put_word((char *)s, c);
		if (!array)
			free_arr(array, i);
		s += ft_strlen(array[i]);
	}
	array[i] = 0;
	return (array);
}
