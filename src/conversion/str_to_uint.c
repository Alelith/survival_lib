/**
 * @file str_to_uint.c
 * @brief Implementation of string to unsigned integer conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Parses a string and converts it to an unsigned integer
 *
 * @details Converts a null-terminated string containing only digit characters
 * to its unsigned integer representation. Processes the entire string or until
 * a non-digit character is encountered. No sign handling is performed.
 *
 * @ingroup conversion_functions
 *
 * @param[in] nptr Null-terminated string containing digits to parse
 *
 * @return The parsed unsigned integer value
 *
 * @note Does not handle overflow; behavior is undefined for values outside unsigned int range
 * @note Does not validate input; passing non-digit characters produces undefined results
 */
unsigned int	str_to_uint(const char *nptr)
{
	unsigned int	result;

	result = 0;
	while (*nptr)
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result);
}
