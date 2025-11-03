#include "printf_internal.h"

/**
 * @file print_str.c
 * @brief Internal implementation of string and character printing for print_format
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Outputs a string or single character to standard output
 *
 * @details Prints either a complete null-terminated string or a single character
 * to file descriptor 1 (stdout). If str is non-NULL, prints the entire string;
 * otherwise, if c is non-zero, prints the single character. Returns the number
 * of characters written.
 *
 * @ingroup print_functions
 *
 * @param[in] str Null-terminated string to print (may be NULL)
 * @param[in] c Single character to print (used if str is NULL and c is non-zero)
 *
 * @return Number of characters written to output
 * @retval 0 Both str is NULL and c is 0
 */
int	print_str(const char *str, char c)
{
	int	len;

	len = 0;
	if (str)
	{
		len = str_len(str);
		write(1, str, len);
	}
	else if (c)
	{
		len = 1;
		write (1, &c, 1);
	}
	return (len);
}
