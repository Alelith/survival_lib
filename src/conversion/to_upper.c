/**
 * @file to_upper.c
 * @brief Implementation of lowercase to uppercase character conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Converts a lowercase letter to uppercase
 *
 * @details Transforms lowercase ASCII letters (a-z) to their uppercase
 * equivalents (A-Z) by subtracting 32 from the ASCII value. Non-lowercase
 * characters are returned unchanged. This function only affects English
 * alphabet letters.
 *
 * @ingroup conversion_functions
 *
 * @param[in] c The character to convert (as integer ASCII value)
 *
 * @return The converted character
 * @retval uppercase The uppercase equivalent if c is lowercase (a-z)
 * @retval c The original character if not lowercase
 */
int	to_upper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
