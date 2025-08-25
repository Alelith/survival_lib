/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:45:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/25 09:16:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"
#include "printf_internal.h"

int	print_format(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				write(1, "%", 1);
			else if (*format == 'd')
				print_nbr(va_arg(args, int));
			else if (*format == 's')
				print_str(va_arg(args, char *));
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (0);
}
