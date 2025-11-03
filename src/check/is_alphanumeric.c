#include "survival_lib.h"

/**
 * @file is_alphanumeric.c
 * @brief Implementation of the is_alphanumeric character validation function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is alphanumeric
 *
 * @details Determines whether the given character is either an alphabetic
 * letter (A-Z, a-z) or a numeric digit (0-9). This function combines the
 * validation logic of is_alphabetic() and is_digit() to provide a unified
 * alphanumeric check.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to validate (as integer ASCII value)
 *
 * @return Integer indicating the result of the validation
 * @retval 1 The character is alphanumeric (letter or digit)
 * @retval 0 The character is not alphanumeric
 */
int	is_alphanumeric(int c)
{
	return (is_alphabetic(c) || is_digit(c));
}
