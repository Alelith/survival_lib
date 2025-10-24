/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:26:52 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/24 22:27:53 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "survival_lib.h"

/**
 * @file float_to_str.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the float_to_str function.
 */

/**
 * @brief Get the of digits and signs that a number contains.
 * 
 * @param nbr The number to evaluate.
 * @param decimals Decimals of accuracy.
 * 
 * @return The length of the number.
 */
static int	float_len(float nbr, int decimals)
{
	int		len;
	int		int_part;

	len = 0;
	if (nbr < 0.0f)
	{
		len++;
		nbr = -nbr;
	}
	int_part = (int)nbr;
	if (int_part == 0)
		len++;
	while (int_part > 0)
	{
		int_part /= 10;
		len++;
	}
	len++;
	len += decimals;
	return (len);
}

/**
 * @brief Fills the result string with the number to convert.
 * 
 * @param result String to insert the numbers.
 * @param nbr The number to convert to string.
 * @param decimals Decimals of accuracy.
 * @param length Length of the number to convert
 */
static void	fill_float_str(char *result, float nbr, int decimals, int length)
{
	int		i;
	int		int_part;
	float	frac_part;
	int		digit;	

	i = length - 1;
	int_part = (int)nbr;
	frac_part = nbr - int_part;
	while (decimals-- > 0)
	{
		frac_part *= 10.0f;
		digit = (int)frac_part;
		result[i--] = digit + '0';
		frac_part -= digit;
	}
	result[i--] = '.';
	if (int_part == 0)
		result[i--] = '0';
	while (int_part > 0)
	{
		result[i--] = (int_part % 10) + '0';
		int_part /= 10;
	}
}

/**
 * @brief Converts a float to a string with specified decimal places.
 * @ingroup conversion_functions
 * 
 * @param n The float to convert.
 * @param decimals The number of decimal places.
 * 
 * @return A pointer to the string representation of the float.
 * @warning Needs to be freed after use.
 */
char	*float_to_str(float n, int decimals)
{
	int		length;
	char	*result;

	length = float_len(n, decimals);
	result = malloc(length + 1);
	if (!result)
		return (0);
	result[length] = '\0';
	if (n < 0.0f)
	{
		result[0] = '-';
		n = -n;
	}
	fill_float_str(result, n, decimals, length);
	return (result);
}
