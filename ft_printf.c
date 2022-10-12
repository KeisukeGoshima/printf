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

void	flag_init(int *flag)
{
	int i;

	i = 0;
	while (i < 6)
		flag[i++] = 0;
}

char	*flag_distribute(char *str, va_list ap, int *flag)
{
	if (*str == '-')
		flag[0] = 1;
	else if (*str == '+')
		flag[1] = 1;
	else if (('1' <= *str && *str <= '9') || ('0' == *str && flag[2] != 0))
		flag[2] = flag[2] * 10 + *str - '0';
	else if (*str == ' ')
		flag[3] = 1;
	else if (*str == '0')
		flag[4] = 1;
	else if (*str == '#')
		flag[5] = 1;
	else
	{
		str--;
		return (str);
	}
	str++;
	return (format_distribute(str, ap, flag));
}

char	*format_distribute(char *str, va_list ap, int *flag)
{
	if (*str == 'c')
		ft_putchar_flag(va_arg(ap, int), flag);
	else if (*str == 's')
		ft_putstr_flag(va_arg(ap, char*), flag, 0);
	else if (*str == 'p')
		convert_address(va_arg(ap, unsigned long long), flag);
	else if (*str == 'd' || *str == 'i')
		convert_standard_num(va_arg(ap, int), 2, flag, 10);
	else if (*str == 'u')
		convert_base(va_arg(ap, unsigned int), 0, flag, 10);
	else if (*str == 'x')
		convert_base(va_arg(ap, int), 0, flag, 16);
	else if (*str == 'X')
		convert_base(va_arg(ap, int), 1, flag, 16);
	else if (*str == '%')
		ft_putchar_fd('%', 1, flag);
	else
		str = flag_distribute(str, ap, flag);
	return (str);
}

void	ft_check_percent(char *str, va_list ap, int *flag)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			str = format_distribute(str, ap, flag);
			flag_init(flag);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1, flag);
			str++;
		}
	}
}

int	ft_printf(const char *argv, ...)
{
    va_list	ap;
    char	*str;
	int		flag[7]; // -, +, num, ' ', 0, #, count 

    str = ft_strdup(argv);
	flag_init(flag);
	flag[6] = 0;
    if (str == NULL)
        return (0);
    va_start(ap, argv);
    ft_check_percent(str, ap, flag);
    va_end(ap);
	free(str);
	return (flag[6]);
}

/*
#include <stdio.h>
int main(void)
{
	unsigned int i = 10;
	ft_printf("%-3d\n", 10);
	printf("%-3d\n", 10);
	printf("----------\n");
	ft_printf("%5i\n", 10);
	printf("%5i\n", 10);
	printf("----------\n");
	printf("%d\n", ft_printf("%-3c\n", 0));
	printf("%d\n", printf("%-3c\n", 0));
	printf("----------\n");
	ft_printf("%-20p\n", LONG_MIN);
	//printf("%-20p\n", LONG_MIN);
	printf("----------\n");
	ft_printf("%3d\n", ft_printf("%s\n", "42tokyo"));
	printf("%3d\n", printf("%s\n", "42tokyo"));
	printf("----------\n");
	ft_printf("%u\n", i);
	printf("%u\n", i);
	printf("----------\n");
	ft_printf("%x\n", 10);
	printf("%x\n", 10);
	printf("----------\n");
	ft_printf("%X\n", 10);
	printf("%X\n", 10);
	printf("----------\n");
	return (0);
}*/