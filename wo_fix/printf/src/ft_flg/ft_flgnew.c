/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:21:58 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:07:44 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_flglst	*ft_flgnew(t_flgtype type, int value)
{
	t_flglst	*result;

	result = malloc(sizeof(t_flglst));
	if (!result)
		return (NULL);
	result -> type = type;
	result -> value = value;
	return (result);
}
