#include "survival_lib.h"

/**
 * @file str_search_str.c
 * @brief Implementation of bounded substring search
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Locates first occurrence of substring within bounded string length
 *
 * @details Searches for the substring 'little' within the first 'len' characters
 * of string 'big'. Returns a pointer to the beginning of the first match.
 * If 'little' is empty, returns 'big'. The search respects the length boundary,
 * ensuring no access beyond 'len' characters or the null terminator.
 *
 * @ingroup string_functions
 *
 * @param[in] big Null-terminated string to search within
 * @param[in] little Null-terminated substring to search for
 * @param[in] len Maximum number of characters to search in big
 *
 * @return Pointer to the first occurrence of little in big
 * @retval NULL Substring not found within the specified length
 * @retval big If little is an empty string
 */
char	*str_search_str(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = str_len(little);
	if (little_len == 0)
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			while (j < little_len && i + j < len
				&& big[i + j] == little[j])
				j++;
			if (j == little_len)
				return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
