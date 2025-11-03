/**
 * @file is_ascii.c
 * @brief Implementation of the is_ascii character validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is within the ASCII range
 *
 * @details Validates whether the given character falls within the standard
 * ASCII character set (0-127). ASCII is a 7-bit character encoding standard
 * that includes control characters (0-31), printable characters (32-126),
 * and the DEL character (127).
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate (as integer value)
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is within ASCII range (0-127)
 * @retval 0 The character is outside ASCII range
 */
int	is_ascii(int c)
{
	return (c >= 0 && c <= 127);
}
