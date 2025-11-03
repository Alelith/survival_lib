#include "survival_lib.h"

/**
 * @file str_duplicate.c
 * @brief Implementation of string duplication with dynamic allocation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Creates an independent copy of a string with dynamic allocation
 *
 * @details Allocates memory for a new string and copies the contents of the
 * source string into it, including the null terminator. Returns NULL if the
 * source pointer is NULL or if memory allocation fails.
 *
 * @ingroup string_functions
 *
 * @param[in] s Null-terminated string to duplicate
 *
 * @return Pointer to the newly allocated duplicate string
 * @retval NULL Source string is NULL or memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*str_duplicate(const char *s)
{
	char	*result;

	if (!s)
		return (0);
	result = malloc(str_len(s) + 1);
	if (!result)
		return (0);
	str_copy(result, s, str_len(s) + 1);
	return (result);
}
