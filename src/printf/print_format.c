#include "printf_internal.h"

/**
 * @file print_format.c
 * @brief Implementation of custom formatted output function
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Processes a format specifier and prints the corresponding argument
 *
 * @details Examines the format character and dispatches to the appropriate
 * printing function for numbers, strings, or characters. Supports various
 * format specifiers including integers, unsigned, hex, pointers, floats,
 * octal, strings, and characters.
 *
 * @param[in] args Variable argument list containing values to format
 * @param[in] format Format specifier character
 *
 * @return Number of characters printed
 */
static int	proccess_format(va_list args, char format)
{
	int		len;

	len = 0;
	if (format == '%')
		len = print_str(0, '%');
	else if (format == 'd' || format == 'i' || format == 'u' || format == 'x'
		|| format == 'X' || format == 'p' || format == 'f' || format == 'o')
		len = print_nbr(args, format);
	else if (format == 's')
		len = print_str(va_arg(args, char *), 0);
	else if (format == 'c')
		len = print_str(0, (char)va_arg(args, int));
	return (len);
}

/**
 * @brief Validates a format specifier character
 *
 * @details Checks if the given character is a recognized format specifier
 * such as d, i, u, x, X, p, f, o, s, c, or the literal % character.
 *
 * @param[in] format Format character to validate
 *
 * @return Validation result
 * @retval 1 Format specifier is valid
 * @retval 0 Format specifier is not recognized
 */
static int	is_valid_format(char format)
{
	return (format == '%' || format == 'd' || format == 'i'
		|| format == 'u' || format == 'x' || format == 'X'
		|| format == 'p' || format == 'f' || format == 'o'
		|| format == 's' || format == 'c');
}

/**
 * @brief Formats and prints a string with variable arguments to standard output
 *
 * @details Parses a format string containing text and format specifiers,
 * replacing each specifier with the corresponding argument from the variable
 * argument list. Format specifiers begin with % followed by a type character.
 * Literal % characters can be printed with %%. Outputs directly to file
 * descriptor 1 (stdout).
 *
 * @ingroup print_functions
 *
 * @param[in] format Null-terminated format string with specifiers
 * @param[in] ... Variable arguments corresponding to format specifiers
 *
 * @return Total number of characters written to output
 */
int	print_format(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && is_valid_format(*(format + 1)))
		{
			format++;
			len += proccess_format(args, *format);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
