/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_search_rev_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:35:15 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/14 17:53:09 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_search_rev_char(const char *s, int c)
{
	const char	*ini_s;

	ini_s = s;
	c = c % 256;
	s += ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + 1);
	while (s >= ini_s)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
