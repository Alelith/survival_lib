#include "survival_lib.h"

/**
 * @file reallocation.c
 * @brief Implementation of memory reallocation with size tracking
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Reallocates a memory block to a new size with data preservation
 *
 * @details Resizes an existing memory block, preserving its contents up to
 * the minimum of old and new sizes. Handles special cases: if ptr is NULL,
 * behaves like callocation; if new_size is 0, frees the memory and returns NULL.
 * Always allocates zero-initialized memory and copies existing data before
 * freeing the old block.
 *
 * @ingroup memory_functions
 *
 * @param[in] ptr Pointer to the memory block to reallocate (may be NULL)
 * @param[in] new_size Desired size of the new memory block in bytes
 * @param[in] old_size Current size of the existing memory block in bytes
 *
 * @return Pointer to the newly allocated memory block
 * @retval NULL Allocation failed or new_size is 0
 *
 * @warning The old pointer becomes invalid after this call and must not be used
 * @warning The returned pointer must be freed with free() to prevent memory leaks
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
