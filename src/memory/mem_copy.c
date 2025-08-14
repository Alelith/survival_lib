/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:01 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/14 17:28:52 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*mem_copy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src && n > 0)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
