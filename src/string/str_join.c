#include "survival_lib.h"

/**
 * @file str_join.c
 * @brief Implementation of string joining with dynamic allocation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Creates a new string by concatenating two strings
 *
 * @details Allocates memory for a new string containing the concatenation
 * of s1 followed by s2. Handles NULL inputs gracefully: if only one string
 * is NULL, returns a duplicate of the non-NULL string; if both are NULL,
 * returns NULL. The result is always a newly allocated string.
 *
 * @ingroup string_functions
 *
 * @param[in] s1 First null-terminated string (may be NULL)
 * @param[in] s2 Second null-terminated string (may be NULL)
 *
 * @return Pointer to newly allocated string containing s1 + s2
 * @retval NULL Both strings are NULL or memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*str_join(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && s2)
		return (str_duplicate(s2));
	if (s1 && !s2)
		return (str_duplicate(s1));
	if (!s1 && !s2)
		return (0);
	result = malloc(str_len(s1) + str_len(s2) + 1);
	if (!result)
		return (0);
	str_copy(result, s1, str_len(s1) + 1);
	str_copy(&result[str_len(s1)], s2, str_len(s2) + 1);
	return (result);
}
