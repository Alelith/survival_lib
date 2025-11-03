#include "survival_lib.h"

/**
 * @file callocation.c
 * @brief Implementation of zero-initialized memory allocation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Allocates and zero-initializes memory for an array of elements
 *
 * @details Allocates a contiguous block of memory sufficient to hold an array
 * of nmemb elements, each of size bytes. All bytes in the allocated memory
 * are initialized to zero. This is equivalent to malloc() followed by memset()
 * to zero, providing a safe starting state for the allocated memory.
 *
 * @ingroup memory_functions
 *
 * @param[in] nmemb Number of elements to allocate
 * @param[in] size Size of each element in bytes
 *
 * @return Pointer to the allocated and zero-initialized memory block
 * @retval NULL Memory allocation failed
 *
 * @warning The returned pointer must be freed with free() to prevent memory leaks
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
