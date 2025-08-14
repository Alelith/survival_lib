/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:59:42 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/06 21:04:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char			*get_next_line(int fd);
char			*ft_strrest(char *s, int start);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(unsigned long nmemb, unsigned long size);
int				ft_strchr(char *s, int c);
unsigned long	ft_strlen(char *s);
#endif