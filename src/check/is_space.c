/**
 * @file is_space.c
 * @brief Implementation of the is_space whitespace validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is a whitespace character
 *
 * @details Determines whether the given character is a whitespace character
 * according to standard C conventions. This includes space (32), tab (9),
 * newline (10), vertical tab (11), form feed (12), and carriage return (13).
 * These characters are commonly used for text formatting and separation.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is a whitespace character
 * @retval 0 The character is not a whitespace character
 */
int	is_space(char c)
{
	return ((c <= 13 && c >= 9) || c == 32);
}
