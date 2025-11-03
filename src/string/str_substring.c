#include "survival_lib.h"
#include <stdlib.h>

/**
 * @file str_substring.c
 * @brief Implementation of substring extraction with dynamic allocation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Extracts a substring from a string with dynamic allocation
 *
 * @details Allocates and returns a new string containing up to 'len' characters
 * starting from index 'start' of the source string. If 'start' is beyond the
 * string length, returns an empty string. If 'len' extends past the string end,
 * only copies available characters. The result is always null-terminated.
 *
 * @ingroup string_functions
 *
 * @param[in] s Source null-terminated string
 * @param[in] start Starting index for extraction (0-based)
 * @param[in] len Maximum number of characters to extract
 *
 * @return Pointer to newly allocated substring
 * @retval NULL Memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*str_substring(char const *s, unsigned int start, size_t len)
{
	unsigned int	srclen;
	char			*result;

	srclen = str_len(s);
	if (start > srclen)
		return (str_duplicate(""));
	if (len > srclen - start)
		len = srclen - start;
	result = malloc(len + 1);
	if (!result)
		return (0);
	str_copy(result, &s[start], len + 1);
	return (result);
}
