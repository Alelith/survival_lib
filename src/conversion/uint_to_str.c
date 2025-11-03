#include "survival_lib.h"

/**
 * @file uint_to_str.c
 * @brief Implementation of unsigned integer to string conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the string length needed for an unsigned integer
 *
 * @details Computes the number of digits required to represent an unsigned
 * integer in decimal notation. Special case handling for zero.
 *
 * @param[in] nbr The unsigned integer to evaluate
 *
 * @return The total number of digits needed
 */
static int	uint_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an unsigned integer to its string representation
 *
 * @details Allocates and generates a null-terminated string containing the
 * decimal representation of the given unsigned integer. The conversion is
 * performed by extracting digits through modulo and division operations,
 * building the string from right to left.
 *
 * @ingroup conversion_functions
 *
 * @param[in] n The unsigned integer to convert
 *
 * @return Pointer to the newly allocated string containing the integer value
 * @retval NULL Memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*uint_to_str(unsigned int n)
{
	char	*str;
	int		len;

	len = uint_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
