#include "printf_internal.h"

/**
 * @file print_nbr.c
 * @brief Internal implementation of numeric value printing for print_format
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 */

/**
 * @brief Converts and prints a numeric value according to format specifier
 *
 * @details Extracts a numeric value from the argument list, converts it to
 * string representation based on the format specifier, and outputs it. Supports
 * signed integers (d, i), unsigned integers (u), hexadecimal (x, X), pointers (p),
 * floating-point (f), and octal (o). Handles memory allocation and cleanup for
 * converted strings. Pointer format includes "0x" prefix.
 *
 * @ingroup print_functions
 *
 * @param[in] args Variable argument list containing the numeric value
 * @param[in] format Format specifier character (d, i, u, x, X, p, f, o)
 *
 * @return Number of characters printed to output
 * @retval 0 String conversion failed (allocation error)
 */
int	print_nbr(va_list args, char format)
{
	char	*str;
	int		len;

	len = 0;
	str = 0;
	if (format == 'd' || format == 'i')
		str = int_to_str(va_arg(args, int));
	else if (format == 'u')
		str = uint_to_str((unsigned int)va_arg(args, int));
	else if (format == 'x' || format == 'X')
		str = bnum_to_str(va_arg(args, unsigned int), 16, format == 'X');
	else if (format == 'p')
	{
		len += print_str("0x", 0);
		str = bnum_to_str((unsigned long)va_arg(args, void *), 16, 0);
	}
	else if (format == 'f')
		str = float_to_str((float)va_arg(args, double), 6);
	else if (format == 'o')
		str = bnum_to_str((unsigned int)va_arg(args, int), 8, 0);
	if (!str)
		return (0);
	len += print_str(str, 0);
	free(str);
	return (len);
}
