/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:32:07 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:06:34 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flgadd_back(t_flglst **lst, t_flglst *new)
{
	t_flglst	*last;

	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	while (last -> next)
		last = last -> next;
	last -> next = new;
}
