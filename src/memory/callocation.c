/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:11:14 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/20 11:38:18 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"
#include <stdlib.h>

void	*callocation(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	set_zero(result, nmemb * size);
	return (result);
}
