/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_substring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:16 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 22:31:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"
#include <stdlib.h>

/**
 * @file str_substring.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the str_substring function.
 */

/**
 * @brief Returns a substring of a string.
 * @ingroup string_functions
 * 
 * @param s The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * 
 * @return A pointer to the substring.
 * @retval NULL if the allocation failed.
 * 
 * @warning Needs to be freed after use.
 */
char	*str_substring(char const *s, unsigned int start, size_t len)
{
	unsigned int	srclen;
	char			*result;

	srclen = str_len(s);
	if (start > srclen)
		return (str_duplicate(""));
	if (len > srclen - start)
		len = srclen - start;
	result = malloc(len + 1);
	if (!result)
		return (0);
	str_copy(result, &s[start], len + 1);
	return (result);
}
