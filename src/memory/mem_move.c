#include "survival_lib.h"

/**
 * @file mem_move.c
 * @brief Implementation of safe memory move for overlapping regions
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Safely moves n bytes from source to destination, handling overlaps
 *
 * @details Copies n bytes from source to destination memory, correctly handling
 * cases where the regions overlap. If destination is within the source region,
 * copies backwards to prevent data corruption. Otherwise, uses forward copy.
 * Returns NULL if either pointer is NULL and n is greater than 0.
 *
 * @ingroup memory_functions
 *
 * @param[out] dest Pointer to the destination memory block
 * @param[in] src Pointer to the source memory block
 * @param[in] n Number of bytes to move
 *
 * @return Pointer to the destination memory block
 * @retval NULL Either dest or src is NULL and n > 0
 *
 * @note Unlike mem_copy, this function handles overlapping regions safely
 */
void	*mem_move(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if ((!dest || !src) && n > 0)
		return (0);
	d = (char *)dest;
	s = (char *)src;
	if (dest >= src && dest <= src + n)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
		mem_copy(dest, src, n);
	return (dest);
}
