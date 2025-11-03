#include "survival_lib.h"

/**
 * @file str_copy.c
 * @brief Implementation of size-bounded string copy operation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Copies source string to destination with size limit
 *
 * @details Safely copies up to size-1 characters from src to dst, always
 * null-terminating the result if size is greater than 0. Returns the length
 * of src to allow detection of truncation. Returns 0 if either pointer is
 * NULL and size is greater than 0.
 *
 * @ingroup string_functions
 *
 * @param[out] dst Destination buffer to receive the string
 * @param[in] src Source null-terminated string to copy
 * @param[in] size Total size of destination buffer
 *
 * @return Length of the source string
 * @retval 0 If src or dst is NULL and size > 0
 *
 * @warning Ensure dst buffer has size bytes allocated
 */
size_t	str_copy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if ((!src || !dst) && size > 0)
		return (0);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (str_len(src));
}
