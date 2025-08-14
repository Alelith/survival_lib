/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:15:39 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/26 12:51:20 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, t_flglst *flags)
{
	if (str)
		return (ft_putstr_fd(str, 1, flags));
	else if (!ft_flgfind(flags, PREC)
		|| (ft_flgfind(flags, PREC)
			&& ft_flgfind(flags, PREC)-> value >= 6))
		return (ft_putstr_fd("(null)", 1, flags));
	else
		return (ft_putstr_fd("", 1, flags));
}
