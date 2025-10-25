/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 22:29:54 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file str_join.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the str_join function.
 */

/**
 * @brief Joins two strings into a new string.
 * @ingroup string_functions
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * 
 * @return A pointer to the new string containing the concatenation of s1 and s2.
 * @retval NULL if the allocation failed.
 * 
 * @warning Needs to be freed after use.
 */
char	*str_join(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && s2)
		return (str_duplicate(s2));
	if (s1 && !s2)
		return (str_duplicate(s1));
	if (!s1 && !s2)
		return (0);
	result = malloc(str_len(s1) + str_len(s2) + 1);
	if (!result)
		return (0);
	str_copy(result, s1, str_len(s1) + 1);
	str_copy(&result[str_len(s1)], s2, str_len(s2) + 1);
	return (result);
}
