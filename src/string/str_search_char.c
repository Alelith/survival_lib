#include "survival_lib.h"

/**
 * @file str_search_char.c
 * @brief Implementation of forward character search in string
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Locates the first occurrence of a character in a string
 *
 * @details Searches the string from left to right for the first occurrence
 * of the specified character. The search includes the null terminator, so
 * searching for '\0' will return a pointer to the end of the string. Uses
 * mem_search internally to perform the byte-level search.
 *
 * @ingroup string_functions
 *
 * @param[in] s Null-terminated string to search
 * @param[in] c Character to locate (converted to char)
 *
 * @return Pointer to the first occurrence of c in s
 * @retval NULL Character not found in string
 */
char	*str_search_char(const char *s, int c)
{
	return (mem_search(s, c, str_len(s) + 1));
}
