#include "survival_lib.h"

/**
 * @file set_zero.c
 * @brief Implementation of memory zeroing utility
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Initializes a memory block to all zeros
 *
 * @details Convenience function that fills n bytes of memory with zeros by
 * calling mem_set with value 0. Useful for clearing buffers and initializing
 * data structures to a known state.
 *
 * @ingroup memory_functions
 *
 * @param[out] s Pointer to the memory block to zero
 * @param[in] n Number of bytes to set to zero
 */
void	set_zero(void *s, size_t n)
{
	mem_set(s, 0, n);
}
