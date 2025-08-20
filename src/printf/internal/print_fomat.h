/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fomat.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:40:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/20 17:30:16 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

int				ft_printf(char const *str, ...);
int				ft_printdec(double num, char type);
int				ft_printchar(char c);
int				ft_printstr(char *str);
int				ft_printnbr(int nbr, char type);
int				ft_printhex(unsigned long hex, char type);
int				ft_putdouble_fd(double d, int fd);
int				ft_putoct_fd(unsigned int n, int fd);
int				ft_putexp_fd(int e, int fd, int upp);
int				ft_putnbr_fd(int n, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putunbr_fd(unsigned int n, int fd);
int				ft_puthex_fd(unsigned long p, int fd, int upp);
int				ft_isflag(char c);
int				ft_isdigit(char c);
int				ft_isupper(char c);
int				ft_isspecifier(char c);
int				ft_intlen(int num);
int				ft_octlen(unsigned int num);
int				ft_uintlen(unsigned int num);
int				ft_hexlen(unsigned long num);
int				ft_atoi(const char **nptr);
unsigned long	ft_strlen(const char *s);

#endif