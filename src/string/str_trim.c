/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:27:42 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 17:29:51 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

int	is_from_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*str_trim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*result;

	if (!s1 || !set)
		return (0);
	end = str_len(s1) - 1;
	start = 0;
	while (s1[start] && is_from_set(s1[start], set))
		start++;
	while (start < end && is_from_set(s1[end], set))
		end--;
	result = str_substring(s1, start, end - start + 1);
	return (result);
}
