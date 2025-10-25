/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:02:03 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 17:32:59 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file reallocation.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the reallocation function.
 */

/**
 * @brief Reallocates clean memory for an array of elements.
 * @ingroup memory_functions
 * 
 * @param ptr The pointer to reallocate.
 * @param new_size The new size of the memory block.
 * @param old_size Current size of the memory block.
 * 
 * @retval A pointer to the allocated memory.
 * @retval NULL if the allocation failed.
 */
void	*reallocation(void *ptr, unsigned long new_size, unsigned long old_size)
{
	void	*new_ptr;

	if (!ptr)
		return (callocation(new_size, 1));
	if (!new_size)
	{
		free(ptr);
		return (0);
	}
	new_ptr = callocation(new_size, 1);
	if (new_ptr == 0)
		return (0);
	if (new_size > old_size)
		mem_copy(new_ptr, ptr, old_size);
	else
		mem_copy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
