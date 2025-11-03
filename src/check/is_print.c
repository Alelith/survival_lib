/**
 * @file is_print.c
 * @brief Implementation of the is_print character validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is printable
 *
 * @details Determines whether the given character is a printable ASCII
 * character. Printable characters include all visible characters plus the
 * space character, corresponding to ASCII values 32-126. This range excludes
 * control characters and non-printable symbols.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate (as integer ASCII value)
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is printable (ASCII 32-126)
 * @retval 0 The character is not printable
 */
int	is_print(int c)
{
	return (c >= 32 && c <= 126);
}
