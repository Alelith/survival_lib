#include "survival_lib.h"

/**
 * @file int_to_str.c
 * @brief Implementation of signed integer to string conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the string length needed to represent an integer
 *
 * @details Computes the total number of characters required to represent
 * a signed integer as a string, including the negative sign if applicable
 * and all digits. Special handling for negative numbers and zero.
 *
 * @param[in] nbr The integer to evaluate
 *
 * @return The total character count needed for string representation
 */
static int	int_len(int nbr)
{
	int	result;

	result = 0;
	if (nbr <= 0)
		result++;
	while (nbr != 0)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

/**
 * @brief Converts a signed integer to its string representation
 *
 * @details Allocates and generates a null-terminated string containing the
 * decimal representation of the given integer. Handles negative numbers by
 * including a minus sign prefix. The conversion is performed by extracting
 * digits through modulo and division operations, building the string from
 * right to left.
 *
 * @ingroup conversion_functions
 *
 * @param[in] n The signed integer to convert
 *
 * @return Pointer to the newly allocated string containing the integer value
 * @retval NULL Memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*int_to_str(int n)
{
	int		length;
	int		sign;
	char	*result;

	length = int_len(n);
	sign = 1;
	result = malloc(length + 1);
	if (!result)
		return (0);
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	if (n == 0)
		result[0] = 48;
	while (n != 0)
	{
		result[length - 1] = sign * (n % 10) + 48;
		n /= 10;
		length--;
	}
	return (result);
}
