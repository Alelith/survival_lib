#include "survival_lib.h"

/**
 * @file mem_len.c
 * @brief Implementation of null-terminated memory block length calculation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the number of elements in a null-terminated memory block
 *
 * @details Counts the number of elements (not bytes) in a null-terminated
 * memory block by checking for null bytes at element boundaries. The block
 * is treated as an array of elements of size blk_size. Counting stops when
 * a null byte is encountered at the start of an element position.
 *
 * @ingroup memory_functions
 *
 * @param[in] ptr Pointer to the start of the memory block
 * @param[in] blk_size Size of each element in bytes (1 for char, 4 for int, 8 for pointers)
 *
 * @return Number of elements before the null terminator
 *
 * @warning The memory block must be null-terminated; undefined behavior otherwise
 * @warning Assumes element boundaries are at multiples of blk_size
 */
int	mem_len(void *ptr, size_t blk_size)
{
	int	len;

	len = 0;
	while (ptr && ((char *)ptr)[len * blk_size])
		len++;
	return (len);
}
