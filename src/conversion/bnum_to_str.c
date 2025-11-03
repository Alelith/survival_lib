#include "survival_lib.h"

/**
 * @file bnum_to_str.c
 * @brief Implementation of arbitrary base number to string conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the string length needed for a number in a given base
 *
 * @details Computes the number of digits required to represent an integer
 * in the specified base (binary, decimal, hexadecimal, etc.). Uses repeated
 * division by the base to count digits.
 *
 * @param[in] nbr The number to evaluate
 * @param[in] base The numeric base (2-16)
 *
 * @return The total number of digits needed in the specified base
 */
static int	bnum_len(int nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an integer to string representation in arbitrary base
 *
 * @details Allocates and generates a null-terminated string containing the
 * representation of the given integer in the specified base (2-16). Supports
 * binary, octal, decimal, and hexadecimal conversions. Letters A-F can be
 * rendered in uppercase or lowercase for bases greater than 10.
 *
 * @ingroup conversion_functions
 *
 * @param[in] n The integer to convert
 * @param[in] base The target base (2-16) for conversion
 * @param[in] is_upper If non-zero, use uppercase letters (A-F) for bases > 10
 *
 * @return Pointer to the newly allocated string in the specified base
 * @retval NULL Memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*bnum_to_str(int n, int base, int is_upper)
{
	const char	*digits;
	char		*result;
	int			i;
	int			length;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	length = bnum_len(n, base);
	i = length - 1;
	result = (char *)malloc(length + 1);
	if (!result)
		return (0);
	if (n == 0)
		result[i--] = '0';
	while (n > 0)
	{
		result[i--] = digits[n % base];
		n /= base;
	}
	result[length] = '\0';
	return (result);
}
