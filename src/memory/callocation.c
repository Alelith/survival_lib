/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:11:14 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 17:31:22 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file callocation.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the callocation function.
 */

/**
 * @brief Allocates clean memory for an array of elements.
 * @ingroup memory_functions
 * 
 * @param nmemb The number of elements.
 * @param size The size of each element.
 * 
 * @retval A pointer to the allocated memory.
 * @retval NULL if the allocation failed.
 */
void	*callocation(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(nmemb * size);
	if (!result)
		return (0);
	set_zero(result, nmemb * size);
	return (result);
}
