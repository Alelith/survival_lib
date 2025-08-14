/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:50:07 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/26 13:45:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_applyprecision(int n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*width;
	t_flglst	*prec;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	prec = ft_flgfind(flags, PREC);
	while (width && !ft_flgfind(flags, ALIGN)
		&& width -> value-- > prec -> value)
		len += ft_putchar_fd(' ', fd, NULL);
	while ((!width && prec -> value-- > ft_uintlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_uintlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	while (ft_flgfind(flags, ALIGN) && width -> value--
		&& prec -> value-- > ft_uintlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	return (len);
}

static int	ft_precision(int n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*prec;
	t_flglst	*width;

	len = 0;
	prec = ft_flgfind(flags, PREC);
	width = ft_flgfind(flags, WIDTH);
	if (prec -> value >= ft_uintlen(n))
	{
		len += ft_applyprecision(n, fd, flags);
		if (n == 0)
			len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	}
	else
	{
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		if (ft_flgfind(flags, ALIGN))
			width -> value--;
		if (n == 0 && width)
			len += ft_putchar_fd(' ', fd, NULL);
	}
	return (len);
}

static int	ft_preprocflags(int n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, 0);
	if (!ft_flgfind(flags, PREC))
	{
		while (!ft_flgfind(flags, ALIGN) && !ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd('0', fd, NULL);
	}
	else
		len += ft_precision(n, fd, flags);
	return (len);
}

static int	ft_postprocflags(int n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, 0);
	if (ft_flgfind(flags, PREC) && width)
		width -> value++;
	while (ft_flgfind(flags, ALIGN)
		&& width && width -> value-- > ft_uintlen(n))
		len += ft_putchar_fd(' ', fd, NULL);
	return (len);
}

int	ft_putunbr_fd(unsigned int n, int fd, t_flglst *flags)
{
	int	len;

	len = 0;
	len += ft_preprocflags(n, fd, flags);
	if (n > 9)
		len += ft_putunbr_fd(n / 10, fd, NULL);
	if (n != 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	len += ft_postprocflags(n, fd, flags);
	return (len);
}
