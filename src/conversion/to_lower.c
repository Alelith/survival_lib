/**
 * @file to_lower.c
 * @brief Implementation of uppercase to lowercase character conversion
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Converts an uppercase letter to lowercase
 *
 * @details Transforms uppercase ASCII letters (A-Z) to their lowercase
 * equivalents (a-z) by adding 32 to the ASCII value. Non-uppercase characters
 * are returned unchanged. This function only affects English alphabet letters.
 *
 * @ingroup conversion_functions
 *
 * @param[in] c The character to convert (as integer ASCII value)
 *
 * @return The converted character
 * @retval lowercase The lowercase equivalent if c is uppercase (A-Z)
 * @retval c The original character if not uppercase
 */
int	to_lower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
