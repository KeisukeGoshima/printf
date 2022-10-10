/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:33:20 by marvin            #+#    #+#             */
/*   Updated: 2022/10/10 20:33:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./42_libft/libft.h"
#include <stdio.h>

static	void flag_init(int *flag)
{
	int i;

	while (i < 5)
		flag[i++] = 0;
}

static void	flag_distribute(char *str, va_list ap, int *flag)
{
	if (*str == '-')
		flag[0] = 1;
	else if (*str == '+')
		flag[1] = 1;
	else if ('1' <= *str <= '9' || ('0' == *str && flag[2] != 0))
		flag[2] = flag[2] * 10 + *str - '0';
	else if (*str == '#')
		flag[3] = 1;
	else if (*str == '0')
		flag[4] = 1;
	else
		return ;
	str++;
	format_distribute(str, ap, flag);
}

static void	format_distribute(char *str, va_list ap, int *flag)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (*str == 's')
		ft_putstr_fd(va_arg(ap, char*), 1);
	else if (*str == 'p')
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*str == 'u')
	else if (*str == 'x')
	else if (*str == 'X')
	else if (*str == '%')
		ft_putchar_fd('%', 1);
	else
		flag_distribute(str, ap, flag);
}

static void	ft_check_percent(char *str, va_list ap, int *flag)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			format_distribute(str, ap, flag);
			flag_init(flag);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
}

int	ft_printf(const char *argv, ...)
{
    va_list	ap;
    char	*str;
	int		flag[5]; // -, +, num, #, 0 

    str = ft_strdup(argv);
	flag_init(flag);
    if (str == NULL)
        return (NULL);
    va_start(ap, argv);
    ft_check_percent(str, ap, flag);
    va_end(ap);
}

int	main(void)
{
    char *str = "42tokyo";

    ft_printf("%s", str);
}