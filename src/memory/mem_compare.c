#include <stddef.h>

/**
 * @file mem_compare.c
 * @brief Implementation of byte-level memory comparison
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Compares two memory blocks byte by byte for equality
 *
 * @details Performs a byte-by-byte comparison of two memory regions of size n.
 * Returns 1 only if all bytes are identical, 0 otherwise. Returns 0 if either
 * pointer is NULL, ensuring safe operation. Unlike standard memcmp, this
 * function returns a boolean equality result rather than a signed difference.
 *
 * @ingroup memory_functions
 *
 * @param[in] s1 Pointer to the first memory block
 * @param[in] s2 Pointer to the second memory block
 * @param[in] n Number of bytes to compare
 *
 * @return Integer indicating equality status
 * @retval 1 All n bytes are identical
 * @retval 0 Memory blocks differ, or a pointer is NULL
 */
int	mem_compare(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*src1;
	const unsigned char	*src2;

	if (!s1 || !s2)
		return (0);
	src1 = (const unsigned char *) s1;
	src2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (0);
		i++;
	}
	return (1);
}
