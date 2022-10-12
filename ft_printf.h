/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:33:35 by marvin            #+#    #+#             */
/*   Updated: 2022/10/10 20:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

int 	ft_printf(const char *argv, ...);
char	*convert_numtostr(unsigned long long n, int base);
char	*ft_itoa_base(int n, int base);
char	convert_0x(int num);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
char	*format_distribute(char *str, va_list ap, int *flag)
void	ft_putstr_fd(char *s, int fd, int *flag);
void	ft_putchar_fd(char c, int fd, int *flag);

#endif