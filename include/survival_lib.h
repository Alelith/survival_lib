/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survival_lib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:11 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/25 18:06:04 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @mainpage Survival Library
 * 
 * This library provides a set of standard functions in C, including
 * check functions, conversion functions, memory functions, and string 
 * functions. It is designed to be a comprehensive utility library for 
 * C programming.
 * 
 * @section intro_sec Introduction
 * The Survival Library is a collection of functions that are 
 * commonly used in C programming.
 * 
 * @section usage_sec Usage
 * To use the Survival Library, include the header file `survival_lib.h` in 
 * your C source files. You can then call the functions provided by the 
 * library.
 * 
 * @section functions_sec Functions
 * The library provides the following categories of functions:
 * - [Check functions](group__check__functions.html): 
 * Functions to check character properties, string equality, etc.
 * - [Conversion functions](group__conversion__functions.html): 
 * Functions to convert between integers and strings,
 *  character case conversion, etc.
 * - [Memory functions](group__memory__functions.html): 
 * Functions for memory allocation, comparison and copying.
 * - [String functions](group__string__functions.html): 
 * Functions for string manipulation, 
 * including concatenation, splitting, and searching.
 * 
 * @section author_sec Authors
 * This library was developed by:
 * - Lilith Estévez Boeta
 */

/**
 * @file survival_lib.h
 * @author Lilith Estévez Boeta
 * @brief This is the header of the standart functions on C
 */

#ifndef SURVIVAL_LIB_H
# define SURVIVAL_LIB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stddef.h>
# include <stdlib.h>

/*=====================================================================
--------------------------- Check functions ---------------------------
=====================================================================*/

/**
 * @defgroup check_functions Check functions
 * @brief Functions to check character properties and string equality.
 */

int				is_alphabetic(int c);
int				is_alphanumeric(int c);
int				is_ascii(int c);
int				is_digit(int c);
int				is_print(int c);
int				is_space(char c);
int				str_compare_all(const char *s1, const char *s2);
int				str_compare_n(const char *s1, const char *s2, size_t n);

/*=====================================================================
------------------------ Conversion functions -------------------------
=====================================================================*/

/**
 * @defgroup conversion_functions Conversion functions
 * @brief Functions for converting between different data types 
 * or representations.
 */

char			*int_to_str(int n);
char			*uint_to_str(unsigned int n);
char			*float_to_str(float n, int decimals);
char			*bnum_to_str(int n, int base, int is_upper);
int				str_to_int(const char *nptr);
unsigned int	str_to_uint(const char *nptr);
float			str_to_float(const char *nptr);
int				to_upper(int c);
int				to_lower(int c);

/*=====================================================================
-------------------------- Memory functions ---------------------------
=====================================================================*/

/**
 * @defgroup memory_functions Memory functions
 * @brief Functions for managing memory.
 */

void			*callocation(size_t nmemb, size_t size);
void			*reallocation(void *ptr, unsigned long new_size,
					unsigned long old_size);
int				mem_compare(const void *s1, const void *s2, size_t n);
void			*mem_copy(void *dest, const void *src, size_t n);
int				mem_len(void *ptr, size_t blk_size);
void			*mem_move(void *dest, const void *src, size_t n);
void			*mem_search(const void *s, int c, size_t n);
void			*mem_set(void *s, int c, size_t n);
void			set_zero(void *s, size_t n);

/*=====================================================================
-------------------------- String functions ---------------------------
=====================================================================*/

/**
 * @defgroup string_functions String functions
 * @brief Functions for manipulating strings.
 */

/**
 * @brief Concatenates two strings.
 * @ingroup string_functions
 * 
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * 
 * @return The total length of the string it tried to create.
 */
size_t			str_concat(char *dst, const char *src, size_t size);

/**
 * @brief Copies a string to a destination buffer.
 * @ingroup string_functions
 * 
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * 
 * @return The total length of the string it tried to create.
 */
size_t			str_copy(char *dst, const char *src, size_t size);

/**
 * @brief Create a duplicate of a string.
 * @ingroup string_functions
 * 
 * @param s The string to duplicate.
 * 
 * @return A pointer to the duplicated string, or NULL if the allocation failed.
 * Needs to be freed after use.
 */
char			*str_duplicate(const char *s);

/**
 * @brief Joins two strings into a new string.
 * @ingroup string_functions
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * 
 * @return A pointer to the new string containing the concatenation of s1 and s2,
 * or NULL if the allocation failed. Needs to be freed after use.
 */
char			*str_join(char const *s1, char const *s2);

/**
 * @brief Returns the length of a string.
 * @ingroup string_functions
 * 
 * @param str The string to measure.
 * 
 * @return The length of the string.
 */
size_t			str_len(const char *str);

/**
 * @brief Searches for the first occurrence of a character in a string.
 * @ingroup string_functions
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character in the string, 
 * or NULL if not found.
 */
char			*str_search_char(const char *s, int c);

/**
 * @brief Searches for the last occurrence of a character in a string.
 * @ingroup string_functions
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the last occurrence of the character in the string, 
 * or NULL if not found.
 */
char			*str_search_rev_char(const char *s, int c);

/**
 * @brief Searches for the first occurrence of a substring in a string.
 * @ingroup string_functions
 * 
 * @param big The string to search.
 * @param little The substring to search for.
 * @param len The number of characters to search.
 * 
 * @return A pointer to the first occurrence of the substring in the string,
 */
char			*str_search_str(const char *big, const char *little,
					size_t len);

char			*str_search_set(const char *s, const char *set);

int				is_from_set(char c, const char *set);

int				str_contains(char *str, char *set);

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 * @ingroup string_functions
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * 
 * @return An array of strings, or NULL if the allocation failed.
 * Needs to be freed after use, including each string in the array.
 */
char			**str_split(char const *s, char c);

/**
 * @brief Returns a substring of a string.
 * @ingroup string_functions
 * 
 * @param s The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * 
 * @return A pointer to the substring, or NULL if the allocation failed.
 * Needs to be freed after use.
 */
char			*str_substring(char const *s, unsigned int start, size_t len);

/**
 * @brief Removes leading and trailing characters from a string.
 * @ingroup string_functions
 * 
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * 
 * @return A pointer to the trimmed string, or NULL if the allocation failed.
 * Needs to be freed after use.
 */
char			*str_trim(char const *s1, char const *set);

/*=====================================================================
--------------------------- Print formatted ---------------------------
=====================================================================*/

/**
 * @defgroup print_functions Print functions
 * @brief Functions for printing in formats.
 */

int				print_format(const char *format, ...);

#endif
