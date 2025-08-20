/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:35:54 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/20 11:56:45 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

int	str_compare(const char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1len = str_len(s1);
	s2len = str_len(s2);
	if (s1len > s2len && s2len < n)
		return (mem_compare(s1, s2, s2len + 1));
	else if (s1len < s2len && s1len < n)
		return (mem_compare(s1, s2, s1len + 1));
	else if (s1len == s2len && s1len < n)
		return (mem_compare(s1, s2, s1len + 1));
	return (mem_compare(s1, s2, n));
}
