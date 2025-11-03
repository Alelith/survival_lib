/**
 * @file is_from_set.c
 * @brief Implementation of the is_from_set character membership function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a character is present in a given character set
 *
 * @details Performs a linear search through the provided character set to
 * determine if the given character is a member. The function iterates through
 * the set string until either a match is found or the null terminator is
 * reached. This is useful for validating characters against custom sets.
 *
 * @ingroup check_functions
 *
 * @param[in] c The character to search for
 * @param[in] set Null-terminated string containing the set of valid characters
 *
 * @return Integer indicating membership status
 * @retval 1 The character is found in the set
 * @retval 0 The character is not in the set
 *
 * @note The set parameter must be null-terminated
 */
int	is_from_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
