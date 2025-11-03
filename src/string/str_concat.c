#include "survival_lib.h"

/**
 * @file str_concat.c
 * @brief Implementation of size-bounded string concatenation
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Appends source string to destination with size limit
 *
 * @details Safely concatenates src to the end of dst, ensuring the result
 * fits within the destination buffer of size bytes (including null terminator).
 * Returns the total length that would have been created if there was sufficient
 * space. If size is less than or equal to dst length, no concatenation occurs.
 *
 * @ingroup string_functions
 *
 * @param[in,out] dst Destination buffer containing initial null-terminated string
 * @param[in] src Source null-terminated string to append
 * @param[in] size Total size of destination buffer
 *
 * @return Total length of string attempted to create (dst_len + src_len)
 *
 * @warning Ensure dst buffer has size bytes allocated
 */
size_t	str_concat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = str_len(dst);
	src_len = str_len(src);
	if (size <= dst_len)
		return (size + src_len);
	while (dst_len + i < size - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
