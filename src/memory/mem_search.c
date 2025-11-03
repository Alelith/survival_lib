#include "survival_lib.h"

/**
 * @file mem_search.c
 * @brief Implementation of byte search within memory block
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Searches for the first occurrence of a byte in a memory block
 *
 * @details Performs a linear search through the first n bytes of the memory
 * block, looking for the first occurrence of the specified byte value. The
 * integer c is converted to unsigned char before comparison. Returns a pointer
 * to the first match, or NULL if not found or if the pointer is NULL.
 *
 * @ingroup memory_functions
 *
 * @param[in] s Pointer to the memory block to search
 * @param[in] c Byte value to search for (converted to unsigned char)
 * @param[in] n Number of bytes to search
 *
 * @return Pointer to the first occurrence of the byte
 * @retval NULL Byte not found within n bytes, or s is NULL
 */
void	*mem_search(const void *s, int c, size_t n)
{
	unsigned char	*src;

	if (!s)
		return (0);
	c = (unsigned char)c;
	src = (unsigned char *) s;
	while (n--)
	{
		if (*src == c)
			return (src);
		src++;
	}
	return (0);
}
