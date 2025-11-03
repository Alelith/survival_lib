/**
 * @mainpage Survival Library Documentation
 *
 * @section intro_sec Introduction
 * The Survival Library is a comprehensive collection of utility functions
 * written in C, designed to provide essential programming tools for system
 * development and general-purpose applications. This library serves as a
 * foundation for building robust C programs with reliable string manipulation,
 * memory management, data conversion, and character validation capabilities.
 *
 * @section features_sec Features
 * - Character validation and string comparison utilities
 * - Type conversion between strings, integers, floats and different bases
 * - Safe memory allocation, copying, and manipulation functions
 * - Comprehensive string processing and manipulation tools
 * - Custom formatted printing functionality
 * - Line reading from file descriptors
 *
 * @section architecture_sec Architecture
 * The library is organized into modular components, each focusing on a specific
 * domain of functionality. All functions are implemented as independent units
 * with minimal dependencies, ensuring flexibility and ease of integration.
 * The header file provides a unified interface to all modules.
 *
 * @ref check_functions Check Functions Module
 * @ref conversion_functions Conversion Functions Module
 * @ref memory_functions Memory Functions Module
 * @ref string_functions String Functions Module
 * @ref print_functions Print Functions Module
 * @ref get_next_line Get Next Line Module
 *
 * @section implementation_sec Implementation
 * All functions are implemented in standard C (C99) with no external
 * dependencies beyond the standard library. The implementation prioritizes
 * clarity, efficiency, and portability across Unix-like systems.
 *
 * @section dependencies_sec Dependencies
 * - Standard C Library (stdlib.h, stddef.h)
 * - File control operations (fcntl.h)
 * - POSIX system calls (unistd.h)
 *
 * @section install_sec Installation
 * 1. Clone the repository
 * 2. Run `make` to compile the library
 * 3. Include `survival_lib.h` in your project
 * 4. Link against the compiled library
 *
 * @section usage_sec Usage
 * Include the header file in your C source files:
 * @code
 * #include "survival_lib.h"
 * @endcode
 * Compile your program with the library:
 * @code
 * gcc -o program program.c -L. -lsurvival
 * @endcode
 *
 * @section contrib_sec Contributing
 * Contributions are welcome. Please ensure all code follows the established
 * style guidelines and includes proper Doxygen documentation. All functions
 * must be thoroughly tested before submission.
 *
 * @section license_sec License
 * This library is released under the terms specified in the LICENSE file.
 * Please refer to the LICENSE file for detailed information.
 */

/**
 * @file survival_lib.h
 * @brief Main header file for the Survival Library
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

#ifndef SURVIVAL_LIB_H
# define SURVIVAL_LIB_H

/**
 * @def BUFFER_SIZE
 * @brief Default buffer size for reading operations
 *
 * @details This macro defines the default buffer size used by the get_next_line
 * function for reading data from file descriptors. The value can be overridden
 * at compile time by defining BUFFER_SIZE before including this header or by
 * using the -D compiler flag. A larger buffer size may improve performance for
 * large files but will consume more memory.
 *
 * @ingroup get_next_line
 *
 * @note This value should be greater than 0 for proper functionality.
 * @warning Extremely large values may cause stack overflow or excessive memory
 * usage.
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/**
 * @defgroup check_functions Check Functions
 * @brief Character validation and string comparison utilities
 *
 * @details This module provides a comprehensive set of functions for validating
 * individual characters and comparing strings. It includes predicates for
 * checking character types (alphabetic, numeric, printable, etc.) and functions
 * for string comparison with various matching strategies.
 *
 * @section check_features_sec Features
 * - ASCII character validation (alphabetic, numeric, alphanumeric)
 * - Printable and whitespace character detection
 * - Character set membership testing
 * - Full and partial string comparison
 * - Substring and character set containment checking
 *
 * @section check_usage_sec Usage
 * Use these functions to validate input, sanitize data, or implement
 * string matching logic. All character checking functions return 1 for true
 * and 0 for false. String comparison functions follow standard C convention
 * returning 0 for equality.
 */

int				is_alphabetic(int c);
int				is_alphanumeric(int c);
int				is_ascii(int c);
int				is_digit(int c);
int				is_from_set(char c, const char *set);
int				is_print(int c);
int				is_space(char c);
int				str_compare_all(const char *s1, const char *s2);
int				str_compare_n(const char *s1, const char *s2, size_t n);
int				str_contains(char *str, char *set);

/**
 * @defgroup conversion_functions Conversion Functions
 * @brief Type conversion and character case transformation utilities
 *
 * @details This module provides bidirectional conversion between strings and
 * numeric types, as well as character case transformation. It supports various
 * number bases and floating-point precision control for string representations.
 *
 * @section conversion_features_sec Features
 * - Integer to string conversion (signed and unsigned)
 * - Floating-point to string with precision control
 * - Arbitrary base number to string conversion (binary, hex, octal, etc.)
 * - String to integer conversion (signed and unsigned)
 * - String to floating-point conversion
 * - Character case conversion (uppercase/lowercase)
 *
 * @section conversion_usage_sec Usage
 * These functions are essential for data serialization, user input parsing,
 * and output formatting. String-to-number functions parse until the first
 * non-numeric character. Number-to-string functions allocate memory that
 * must be freed by the caller.
 *
 * @warning All string-returning functions allocate memory that must be freed.
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

/**
 * @defgroup memory_functions Memory Functions
 * @brief Low-level memory allocation and manipulation utilities
 *
 * @details This module provides fundamental memory management operations
 * including allocation, deallocation, copying, comparison, and initialization.
 * These functions operate on raw byte sequences and provide fine-grained
 * control over memory operations.
 *
 * @section memory_features_sec Features
 * - Zero-initialized memory allocation (callocation)
 * - Safe memory reallocation with size tracking
 * - Byte-level memory comparison
 * - Memory copying with non-overlapping regions
 * - Safe memory move for overlapping regions
 * - Memory pattern searching
 * - Memory initialization with specific byte values
 * - Memory block length calculation
 * - Zero-initialization utilities
 *
 * @section memory_usage_sec Usage
 * Use these functions for low-level memory management when standard library
 * functions are unavailable or when specific behavior is required. Always
 * free allocated memory to prevent leaks. Be cautious with pointer arithmetic
 * and buffer boundaries to avoid undefined behavior.
 *
 * @warning Improper use can lead to memory leaks, buffer overflows, or
 * undefined behavior. Always validate pointer arguments and sizes.
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

/**
 * @defgroup string_functions String Functions
 * @brief High-level string manipulation and processing utilities
 *
 * @details This module provides a comprehensive suite of string operations
 * including concatenation, copying, searching, splitting, and transformation.
 * All functions handle null-terminated C strings and provide safe operations
 * with proper bounds checking where applicable.
 *
 * @section string_features_sec Features
 * - Safe string concatenation and copying with size limits
 * - String duplication with dynamic allocation
 * - String joining and splitting by delimiter
 * - Forward and reverse character searching
 * - Substring extraction and searching
 * - String trimming (whitespace and custom character sets)
 * - String length calculation
 *
 * @section string_usage_sec Usage
 * These functions form the foundation for text processing and string
 * manipulation tasks. Functions that allocate memory (duplicate, join, split,
 * substring, trim) return pointers that must be freed by the caller. Size-bound
 * functions (concat, copy) prevent buffer overflows by accepting buffer sizes.
 *
 * @warning Functions that allocate memory must have their return values freed.
 * Always ensure destination buffers are large enough for copy operations.
 */

size_t			str_concat(char *dst, const char *src, size_t size);
size_t			str_copy(char *dst, const char *src, size_t size);
char			*str_duplicate(const char *s);
char			*str_join(char const *s1, char const *s2);
size_t			str_len(const char *str);
char			*str_search_char(const char *s, int c);
char			*str_search_rev_char(const char *s, int c);
char			*str_search_str(const char *big, const char *little,
					size_t len);
char			**str_split(char const *s, char c);
char			*str_substring(char const *s, unsigned int start, size_t len);
char			*str_trim(char const *s1, char const *set);

/**
 * @defgroup print_functions Print Functions
 * @brief Custom formatted output utilities
 *
 * @details This module provides a printf-like function for formatted output
 * with support for various format specifiers. It enables flexible text
 * formatting and output generation for console applications.
 *
 * @section print_features_sec Features
 * - Variable argument formatted printing
 * - Support for multiple format specifiers
 * - Dynamic output generation
 *
 * @section print_usage_sec Usage
 * Use print_format() similarly to printf() for generating formatted output.
 * The function accepts a format string followed by variable arguments
 * corresponding to the format specifiers.
 */

int				print_format(const char *format, ...);

/**
 * @defgroup get_next_line Get Next Line
 * @brief Line-by-line file reading utility
 *
 * @details This module provides functionality to read text files line by line
 * from file descriptors. It maintains internal state to handle partial reads
 * and supports reading from multiple file descriptors concurrently.
 *
 * @section gnl_features_sec Features
 * - Sequential line reading from file descriptors
 * - Configurable buffer size (BUFFER_SIZE)
 * - Support for multiple concurrent file descriptors
 * - Automatic memory management for line storage
 *
 * @section gnl_usage_sec Usage
 * Call get_next_line() repeatedly with a file descriptor to read each line
 * from a file. The function returns NULL when EOF is reached or on error.
 * Each returned line must be freed by the caller.
 *
 * @warning Returned lines must be freed to prevent memory leaks.
 */

char			*get_next_line(int fd);

#endif
