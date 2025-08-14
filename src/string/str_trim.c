/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:27:42 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/14 17:52:37 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_from_set(char c, const char *set)
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
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && is_from_set(s1[start], set))
		start++;
	while (start < end && is_from_set(s1[end], set))
		end--;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
