/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 17:29:34 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"
#include <stdlib.h>

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
