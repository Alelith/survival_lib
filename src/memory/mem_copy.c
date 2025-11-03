#include "survival_lib.h"

/**
 * @file mem_copy.c
 * @brief Implementation of non-overlapping memory copy operation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Copies n bytes from source to destination memory
 *
 * @details Performs a byte-by-byte copy of n bytes from the source memory
 * region to the destination memory region. The memory regions must not overlap;
 * use mem_move() for overlapping regions. Returns NULL if either pointer is
 * NULL and n is greater than 0.
 *
 * @ingroup memory_functions
 *
 * @param[out] dest Pointer to the destination memory block
 * @param[in] src Pointer to the source memory block
 * @param[in] n Number of bytes to copy
 *
 * @return Pointer to the destination memory block
 * @retval NULL Either dest or src is NULL and n > 0
 *
 * @warning Source and destination must not overlap; use mem_move() for overlapping regions
 */
void	*mem_copy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if ((!dest || !src) && n > 0)
		return (0);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
