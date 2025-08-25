/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:48:45 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/24 23:14:03 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"
#include "printf_internal.h"

int	print_nbr(int n, char format)
{
	char	*str;
	int		len;

	len = 0;
	str = NULL;
	if (format == 'd' || format == 'i')
		str = int_to_str(n);
	else if (format == 'u')
		str = uint_to_str((unsigned int)n);
	else if (format == 'x' || format == 'X')
		str = bnum_to_str(n, 16, format == 'X');
	else if (format == 'p')
	{
		len += print_str("0x");
		str = bnum_to_str((unsigned long)n, 16, 0);
	}
	else if (format == 'f')
		str = float_to_str((float)n, 6);
	else if (format == 'o')
		str = bnum_to_str(n, 8, 0);
	if (!str)
		return (0);
	len += print_str(str);
	free(str);
	return (len);
}
