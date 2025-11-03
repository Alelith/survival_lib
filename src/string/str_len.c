#include "survival_lib.h"

/**
 * @file str_len.c
 * @brief Implementation of string length calculation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the length of a null-terminated string
 *
 * @details Counts the number of characters in the string up to but not
 * including the null terminator. Returns 0 if the string pointer is NULL,
 * ensuring safe operation.
 *
 * @ingroup string_functions
 *
 * @param[in] s Null-terminated string to measure
 *
 * @return Number of characters in the string (excluding null terminator)
 * @retval 0 If s is NULL
 */
size_t	str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
