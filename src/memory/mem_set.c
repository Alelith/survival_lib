#include "survival_lib.h"

/**
 * @file mem_set.c
 * @brief Implementation of memory block initialization with specific byte value
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Fills a memory block with a specified byte value
 *
 * @details Sets each of the first n bytes of the memory block to the specified
 * value c (converted to unsigned char). Fills the memory backwards from the
 * last byte to the first. Returns the original pointer to the memory block,
 * or NULL if s is NULL.
 *
 * @ingroup memory_functions
 *
 * @param[out] s Pointer to the memory block to fill
 * @param[in] c Byte value to set (converted to unsigned char)
 * @param[in] n Number of bytes to set
 *
 * @return Pointer to the memory block
 * @retval NULL If s is NULL
 */
void	*mem_set(void *s, int c, size_t n)
{
	char	*src;

	src = (char *) s;
	while (s && n > 0)
	{
		src[n - 1] = c;
		n--;
	}
	return (s);
}
