#include "survival_lib.h"

/**
 * @file str_compare_n.c
 * @brief Implementation of the str_compare_n bounded string comparison function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Compares up to n characters of two strings for equality
 *
 * @details Performs a bounded string comparison, checking at most n characters.
 * If either string is shorter than n characters, the comparison includes the
 * null terminator to ensure proper handling of string boundaries. Returns 1
 * if n is 0 (empty comparison is considered equal). Returns 0 if either
 * pointer is NULL for safe operation.
 *
 * @ingroup check_functions
 *
 * @param[in] s1 First null-terminated string to compare
 * @param[in] s2 Second null-terminated string to compare
 * @param[in] n Maximum number of characters to compare
 *
 * @return Integer indicating equality status within the specified range
 * @retval 1 The first n characters match, or n is 0
 * @retval 0 The strings differ within n characters, or a pointer is NULL
 */
int	str_compare_n(const char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	s1len = str_len(s1);
	s2len = str_len(s2);
	if (s1len > s2len && s2len < n)
		return (mem_compare(s1, s2, s2len + 1));
	else if (s1len <= s2len && s1len < n)
		return (mem_compare(s1, s2, s1len + 1));
	return (mem_compare(s1, s2, n));
}
