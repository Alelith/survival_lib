/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:35:54 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/14 17:24:50 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_compare(const char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len > s2len && s2len < n)
		return (ft_memcmp(s1, s2, s2len + 1));
	else if (s1len < s2len && s1len < n)
		return (ft_memcmp(s1, s2, s1len + 1));
	else if (s1len == s2len && s1len < n)
		return (ft_memcmp(s1, s2, s1len + 1));
	return (ft_memcmp(s1, s2, n));
}
