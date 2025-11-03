/**
 * @file is_alphabetic.c
 * @brief Implementation of the is_alphabetic character validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is an alphabetic letter
 *
 * @details Determines whether the given character is an uppercase (A-Z) or
 * lowercase (a-z) alphabetic letter according to ASCII encoding. This function
 * validates characters based on their ASCII values: 65-90 for uppercase and
 * 97-122 for lowercase letters.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate (as integer ASCII value)
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is an alphabetic letter (A-Z or a-z)
 * @retval 0 The character is not an alphabetic letter
 */
int	is_alphabetic(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
