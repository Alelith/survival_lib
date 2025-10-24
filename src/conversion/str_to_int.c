/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:26 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/24 22:31:06 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file str_to_int.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the str_to_int function.
 */

/**
 * @brief Converts a string to an integer.
 * @ingroup conversion_functions
 * 
 * @param nptr The string to convert.
 * 
 * @return The integer representation of the string.
 */
int	str_to_int(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		result = (result * 10) + (*nptr - 48);
		nptr++;
	}
	return (result * sign);
}
