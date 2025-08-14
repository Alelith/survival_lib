/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:15:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/14 17:52:19 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(char const *s, char delimiter)
{
	int	isdelimiter;
	int	wordcount;

	isdelimiter = 1;
	wordcount = 0;
	while (s && *s)
	{
		if (*s == delimiter)
			isdelimiter = 1;
		else if (isdelimiter && *s != delimiter)
		{
			isdelimiter = 0;
			wordcount++;
		}
		s++;
	}
	return (wordcount);
}

static void	*fill_arr(char **result, char *str, int wordcount, char c)
{
	int	i;
	int	next;

	i = 0;
	next = 0;
	while (wordcount-- && str && *str)
	{
		while (str[next] != c && str[next])
			next++;
		result[i] = ft_substr(str, 0, next);
		if (!result[i] || result[i][0] == 0)
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		str += next + 1;
		while (*str == c)
			str++;
		next = 0;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**str_split(char const *s, char c)
{
	int		wordcount;
	char	*cleanstr;
	char	**result;

	wordcount = word_count(s, c);
	cleanstr = ft_strtrim(s, &c);
	if (!cleanstr)
		return (NULL);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
	{
		free(cleanstr);
		return (NULL);
	}
	result = fill_arr(result, cleanstr, wordcount, c);
	free(cleanstr);
	return (result);
}
