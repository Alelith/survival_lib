#include "survival_lib.h"

/**
 * @file str_search_rev_char.c
 * @brief Implementation of reverse character search in string
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Locates the last occurrence of a character in a string
 *
 * @details Searches the string from right to left for the last occurrence
 * of the specified character. The character c is taken modulo 256 to ensure
 * it fits in a char. Special handling for null terminator: returns pointer
 * to the null byte. Searches backwards from the end of the string to the
 * beginning.
 *
 * @ingroup string_functions
 *
 * @param[in] s Null-terminated string to search
 * @param[in] c Character to locate (converted to char via modulo 256)
 *
 * @return Pointer to the last occurrence of c in s
 * @retval NULL Character not found in string
 */
char	*str_search_rev_char(const char *s, int c)
{
	const char	*ini_s;

	ini_s = s;
	c = c % 256;
	s += str_len(s) - 1;
	if (c == '\0')
		return ((char *)s + 1);
	while (s >= ini_s)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
