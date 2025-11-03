#include "survival_lib.h"

/**
 * @file float_to_str.c
 * @brief Implementation of floating-point to string conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the string length needed for a floating-point number
 *
 * @details Computes the total character count including the sign (if negative),
 * all integer digits, the decimal point, and the specified number of decimal
 * places. Handles negative numbers and zero appropriately.
 *
 * @param[in] nbr The floating-point number to evaluate
 * @param[in] decimals The number of decimal places to include
 *
 * @return The total character count needed for string representation
 */
static int	float_len(float nbr, int decimals)
{
	int		len;
	int		int_part;

	len = 0;
	if (nbr < 0.0f)
	{
		len++;
		nbr = -nbr;
	}
	int_part = (int)nbr;
	if (int_part == 0)
		len++;
	while (int_part > 0)
	{
		int_part /= 10;
		len++;
	}
	len++;
	len += decimals;
	return (len);
}

/**
 * @brief Fills the decimal portion of the float string representation
 *
 * @details Converts the fractional part to decimal digits by repeatedly
 * multiplying by 10 and extracting the integer portion. Places the decimal
 * point before the fractional digits. Returns the position where integer
 * digit insertion should end.
 *
 * @param[out] result The string buffer to fill
 * @param[in] frac_part The fractional component (0.0 to 1.0)
 * @param[in] decimals Number of decimal places to generate
 * @param[in] length Total string length
 *
 * @return Index where the least significant integer digit should be placed
 */
static int	fill_decimal_part(char *result, float frac_part,
					int decimals, int length)
{
	int	pos;
	int	k;
	int	digit;

	pos = length - decimals;
	k = 0;
	while (k < decimals)
	{
		frac_part *= 10.0f;
		digit = (int)frac_part;
		result[pos + k] = digit + '0';
		frac_part -= digit;
		k++;
	}
	result[pos - 1] = '.';
	return (pos - 2);
}

/**
 * @brief Fills the integer portion of the float string representation
 *
 * @details Converts the integer part to decimal digits by extracting through
 * modulo and division operations. Builds the digits from right to left,
 * starting at the specified index position.
 *
 * @param[out] result The string buffer to fill
 * @param[in] int_part The integer component
 * @param[in] end_idx The rightmost position for integer digits
 */
static void	fill_integer_part(char *result, int int_part, int end_idx)
{
	if (int_part == 0)
	{
		result[end_idx] = '0';
		return ;
	}
	while (int_part > 0)
	{
		result[end_idx] = (int_part % 10) + '0';
		end_idx--;
		int_part /= 10;
	}
}

/**
 * @brief Orchestrates the complete float-to-string conversion process
 *
 * @details Separates the number into integer and fractional components,
 * then delegates to specialized functions to fill each portion of the
 * string representation. Coordinates the placement of all digits and
 * the decimal point.
 *
 * @param[out] result The string buffer to fill
 * @param[in] nbr The floating-point number (absolute value)
 * @param[in] decimals Number of decimal places
 * @param[in] length Total string length
 */
static void	fill_float_str(char *result, float nbr, int decimals, int length)
{
	int		int_part;
	float	frac_part;
	int		end_idx;

	int_part = (int)nbr;
	frac_part = nbr - int_part;
	end_idx = fill_decimal_part(result, frac_part, decimals, length);
	fill_integer_part(result, int_part, end_idx);
}

/**
 * @brief Converts a floating-point number to string with precision control
 *
 * @details Allocates and generates a null-terminated string containing the
 * decimal representation of the given float with the specified number of
 * decimal places. Handles negative numbers by including a minus sign prefix.
 * The conversion separates integer and fractional parts for accurate
 * representation.
 *
 * @ingroup conversion_functions
 *
 * @param[in] n The floating-point number to convert
 * @param[in] decimals Number of decimal places to include in output
 *
 * @return Pointer to the newly allocated string containing the float value
 * @retval NULL Memory allocation failed
 *
 * @warning The returned string must be freed by the caller to prevent memory leaks
 */
char	*float_to_str(float n, int decimals)
{
	int		length;
	char	*result;

	length = float_len(n, decimals);
	result = malloc(length + 1);
	if (!result)
		return (0);
	result[length] = '\0';
	if (n < 0.0f)
	{
		result[0] = '-';
		n = -n;
	}
	fill_float_str(result, n, decimals, length);
	return (result);
}
