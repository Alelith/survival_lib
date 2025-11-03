/**
 * @file is_digit.c
 * @brief Implementation of the is_digit character validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is a numeric digit
 *
 * @details Determines whether the given character is a decimal digit (0-9)
 * according to ASCII encoding. This function validates characters based on
 * their ASCII values: 48-57 correspond to digits '0' through '9'.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate (as integer ASCII value)
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is a numeric digit (0-9)
 * @retval 0 The character is not a numeric digit
 */
int	is_digit(int c)
{
	return (c >= 48 && c <= 57);
}
