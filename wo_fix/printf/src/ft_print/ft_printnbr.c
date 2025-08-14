/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:53:19 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/26 13:46:36 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr, char type, t_flglst *flags)
{
	if (type == 'i' || type == 'd')
		return (ft_putnbr_fd(nbr, 1, flags));
	else if (type == 'u')
		return (ft_putunbr_fd(nbr, 1, flags));
	else if (type == 'o')
		return (ft_putoct_fd(nbr, 1));
	return (0);
}
