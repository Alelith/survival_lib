/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:15:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 22:31:07 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file str_split.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the str_split function.
 */

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 * @ingroup string_functions
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * 
 * @return The splitted string in a lis of strings NULL terminated.
 * @retval NULL if the allocation failed.
 * @warning Needs to be freed after use, including each string in the array.
 */
char	**str_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	len = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		res = reallocation(res, sizeof(char *) * (len + 1),
				sizeof(char *) * len);
		if (str_search_char(&s[i], c))
			res[len] = str_substring(&s[i], 0,
					str_search_char(&s[i], c) - &s[i]);
		else
			res[len] = str_substring(&s[i], 0, str_len(&s[i]));
	}
	res = reallocation(res, sizeof(char *) * (len + 1),
			sizeof(char *) * len);
	return (res);
}
