/**
 * @file printf_internal.h
 * @brief Internal header for print_format implementation functions
 *
 * @author Lilith Estévez Boeta
 * @date November 3, 2025
 *
 * @note This header is for internal use by the print_format module only
 */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include <stdarg.h>
# include <unistd.h>
# include "survival_lib.h"

int		print_nbr(va_list args, char format);
int		print_str(const char *str, char c);

#endif
