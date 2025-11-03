/**
 * @file str_to_float.c
 * @brief Implementation of string to floating-point conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Parses the fractional portion of a floating-point number
 *
 * @details Extracts and converts the decimal digits following a decimal point
 * to their floating-point representation. Each digit is weighted by decreasing
 * powers of 10 (0.1, 0.01, 0.001, etc.) to build the fractional value.
 *
 * @param[in] nptr Pointer to the first digit after the decimal point
 *
 * @return The fractional component as a float (0.0 to less than 1.0)
 */
static float	parse_decimal(const char *nptr)
{
	float	result;
	float	decimal_place;

	result = 0.0f;
	decimal_place = 0.1f;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		result += (*nptr - '0') * decimal_place;
		decimal_place *= 0.1f;
		nptr++;
	}
	return (result);
}

/**
 * @brief Parses a string and converts it to a floating-point number
 *
 * @details Converts a null-terminated string to its floating-point representation.
 * Handles optional leading '+' or '-' sign, integer part, decimal point, and
 * fractional part. Parsing continues through valid numeric characters and stops
 * at the first invalid character. Leading whitespace is not skipped.
 *
 * @ingroup conversion_functions
 *
 * @param[in] nptr Null-terminated string containing the number to parse
 *
 * @return The parsed floating-point value
 * @retval 0.0 If no valid digits are found in the string
 *
 * @note Leading whitespace is not automatically skipped
 */
float	str_to_float(const char *nptr)
{
	int		sign;
	float	result;

	sign = 1;
	result = 0.0f;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10.0f) + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		result += parse_decimal(nptr);
	}
	return (result * sign);
}
