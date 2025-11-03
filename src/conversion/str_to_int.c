/**
 * @file str_to_int.c
 * @brief Implementation of string to signed integer conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Parses a string and converts it to a signed integer
 *
 * @details Converts a null-terminated string to its integer representation.
 * Handles optional leading '+' or '-' sign for positive and negative values.
 * Parsing continues through consecutive digit characters and stops at the
 * first non-digit character. Leading whitespace is not skipped.
 *
 * @ingroup conversion_functions
 *
 * @param[in] nptr Null-terminated string containing the number to parse
 *
 * @return The parsed integer value
 * @retval 0 If no valid digits are found in the string
 *
 * @note Does not handle overflow; behavior is undefined for values outside int range
 * @note Leading whitespace is not automatically skipped
 */
int	str_to_int(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		result = (result * 10) + (*nptr - 48);
		nptr++;
	}
	return (result * sign);
}
