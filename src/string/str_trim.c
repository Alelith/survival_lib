#include "survival_lib.h"

/**
 * @file str_trim.c
 * @brief Implementation of string trimming with custom character set
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Removes leading and trailing characters from a string
 *
 * @details Creates a new string with all leading and trailing characters
 * that appear in the 'set' parameter removed from the source string. Only
 * characters at the beginning and end are removed; internal characters are
 * preserved. Returns NULL if either input pointer is NULL or if allocation fails.
 *
 * @ingroup string_functions
 *
 * @param[in] s1 Null-terminated string to trim
 * @param[in] set Null-terminated string containing characters to remove
 *
 * @return Pointer to newly allocated trimmed string
 * @retval NULL Either input is NULL or memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*str_trim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*result;

	if (!s1 || !set)
		return (0);
	end = str_len(s1) - 1;
	start = 0;
	while (s1[start] && is_from_set(s1[start], set))
		start++;
	while (start < end && is_from_set(s1[end], set))
		end--;
	result = str_substring(s1, start, end - start + 1);
	return (result);
}
