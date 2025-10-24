/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:33:36 by acesteve          #+#    #+#             */
/*   Updated: 2025/10/24 22:39:44 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file to_lower.c
 * @author Lilith Estévez Boeta
 * @brief This file contains the implementation of the to_lower function.
 */

/**
 * @brief Converts a character to lowercase.
 * @ingroup conversion_functions
 * 
 * @param c The character to convert.
 * 
 * @retval The lowercase version of the char if is alphabetic.
 * @retval The original character if is not alphabetic.
 */
int	to_lower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
