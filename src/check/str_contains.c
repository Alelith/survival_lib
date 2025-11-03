#include "survival_lib.h"

/**
 * @file str_contains.c
 * @brief Implementation of the str_contains set membership function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Checks if a string contains any character from a given set
 *
 * @details Iterates through the entire string and checks each character
 * against the provided character set. Returns immediately upon finding the
 * first match. This is useful for validating whether a string contains any
 * forbidden or required characters from a specific set.
 *
 * @ingroup check_functions
 *
 * @param[in] str Null-terminated string to search through
 * @param[in] set Null-terminated string containing the set of characters
 *
 * @return Integer indicating whether any set character is found
 * @retval 1 At least one character from set is found in str
 * @retval 0 No characters from set are found in str, or str is NULL
 */
int	str_contains(char *str, char *set)
{
	while (str && *str)
	{
		if (is_from_set(*str, set))
			return (1);
		str++;
	}
	return (0);
}
