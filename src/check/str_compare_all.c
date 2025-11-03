#include "survival_lib.h"

/**
 * @file str_compare_all.c
 * @brief Implementation of the str_compare_all string comparison function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Compares two strings for complete equality
 *
 * @details Performs a full string comparison by first checking if the strings
 * have equal lengths, then comparing their contents byte-by-byte. Both strings
 * must have identical lengths and content to be considered equal. Returns 0
 * if either pointer is NULL, ensuring safe operation.
 *
 * @ingroup check_functions
 *
 * @param[in] s1 First null-terminated string to compare
 * @param[in] s2 Second null-terminated string to compare
 *
 * @return Integer indicating equality status
 * @retval 1 The strings are completely equal in length and content
 * @retval 0 The strings differ in length or content, or a pointer is NULL
 */
int	str_compare_all(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (0);
	s1len = str_len(s1);
	s2len = str_len(s2);
	if (s1len != s2len)
		return (0);
	return (mem_compare(s1, s2, s1len));
}
