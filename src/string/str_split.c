#include "survival_lib.h"

/**
 * @file str_split.c
 * @brief Implementation of string tokenization by delimiter
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Calculates the length of a word up to the delimiter
 *
 * @details Counts characters from the current position until the delimiter
 * character or null terminator is encountered.
 *
 * @param[in] s String to analyze
 * @param[in] c Delimiter character
 *
 * @return Length of the word in characters
 */
static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s && s[len] && s[len] != c)
		len++;
	return (len);
}

/**
 * @brief Frees all allocated strings in the split result array
 *
 * @details Iterates through the array and frees each string, then frees
 * the array itself. Used for cleanup on allocation failure.
 *
 * @param[in] res Array of allocated strings
 * @param[in] len Number of strings to free
 */
static void	free_split_array(char **res, int len)
{
	while (len > 0)
		free(res[--len]);
	free(res);
}

/**
 * @brief Extracts a word and adds it to the result array
 *
 * @details Reallocates the result array to accommodate a new word, extracts
 * the substring from the source string up to the delimiter or end, and stores
 * it in the array. Updates the length counter.
 *
 * @param[in] res Current result array
 * @param[in] s Position in source string where word starts
 * @param[in] c Delimiter character
 * @param[in,out] len Pointer to current array length (incremented on success)
 *
 * @return Reallocated array with new word added
 * @retval NULL Reallocation or substring extraction failed
 */
static char	**add_word(char **res, char const *s, char c, int *len)
{
	char	**tmp;
	char	*word_end;

	tmp = reallocation(res, sizeof(char *) * (*len + 2),
			sizeof(char *) * (*len + 1));
	if (!tmp)
		return (NULL);
	res = tmp;
	word_end = str_search_char(s, c);
	if (word_end)
		res[*len] = str_substring(s, 0, word_end - s);
	else
		res[*len] = str_substring(s, 0, str_len(s));
	if (!res[*len])
		return (NULL);
	(*len)++;
	return (res);
}

/**
 * @brief Main loop that processes string and extracts all words
 *
 * @details Iterates through the source string, skipping consecutive delimiters
 * and extracting each word found between delimiters. Updates the result array
 * and length counter as words are added.
 *
 * @param[in] s Source string to split
 * @param[in] c Delimiter character
 * @param[in,out] res Pointer to result array pointer
 * @param[in,out] len Pointer to array length counter
 *
 * @return Status code
 * @retval 0 Success
 * @retval -1 Allocation error occurred
 */
static int	split_loop(char const *s, char c, char ***res, int *len)
{
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		*res = add_word(*res, &s[i], c, len);
		if (!*res)
			return (-1);
		i += word_len(&s[i], c);
	}
	return (0);
}

/**
 * @brief Splits a string into an array of substrings using a delimiter
 *
 * @details Tokenizes the input string by the delimiter character, creating
 * a null-terminated array of dynamically allocated substrings. Consecutive
 * delimiters are treated as a single separator (empty tokens are not created).
 * The result array and all contained strings must be freed individually.
 *
 * @ingroup string_functions
 *
 * @param[in] s Null-terminated string to split
 * @param[in] c Delimiter character
 *
 * @return Null-terminated array of substring pointers
 * @retval NULL Source string is NULL or memory allocation failed
 *
 * @warning Both the array and each string within must be freed by the caller
 */
char	**str_split(char const *s, char c)
{
	int		len;
	char	**tmp;
	char	**res;

	if (!s)
		return (NULL);
	len = 0;
	res = NULL;
	if (split_loop(s, c, &res, &len) == -1)
	{
		free_split_array(res, len);
		return (NULL);
	}
	tmp = reallocation(res, sizeof(char *) * (len + 1),
			sizeof(char *) * len);
	if (!tmp)
	{
		free_split_array(res, len);
		return (NULL);
	}
	res = tmp;
	res[len] = NULL;
	return (res);
}
