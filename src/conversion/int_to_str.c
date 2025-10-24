/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:27:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/24 22:27:53 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file int_to_str.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the int_to_str function.
 */

/**
 * @brief Get the of digits and signs that a number contains.
 * 
 * @param nbr The number to evaluate.
 * 
 * @return The length of the number.
 */
static int	int_len(int nbr)
{
	int	result;

	result = 0;
	if (nbr <= 0)
		result++;
	while (nbr != 0)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

/**
 * @brief Converts an integer to a string.
 * @ingroup conversion_functions
 * 
 * @param n The integer to convert.
 * 
 * @return A pointer to the string representation of the integer.
 * @warning Needs to be freed after use.
 */
char	*int_to_str(int n)
{
	int		length;
	int		sign;
	char	*result;

	length = int_len(n);
	sign = 1;
	result = malloc(length + 1);
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	if (n == 0)
		result[0] = 48;
	while (n != 0)
	{
		result[length - 1] = sign * (n % 10) + 48;
		n /= 10;
		length--;
	}
	return (result);
}
