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
#include <limits.h>

void	flag_init(int *flag)
{
	int i;

	i = 0;
	while (i < 5)
		flag[i++] = 0;
}

void	ft_putoutput(char *output, int *flag)
{
	if (flag[1] == ' ' || flag[1] == '+')
		ft_putchar_fd(flag[1], 1, flag);
	ft_putstr_fd(output, 1, flag);
}

void	ft_putstr_flag(char *output, int *flag, int option) // -, +, num, ' ', 0 
{
	int	len;

	if (output == NULL)
	{
		ft_putstr_fd("(null)", 1, flag);
		return ;
	}
	len = ft_strlen(output);
	if (output[0] != '-' && flag[1] == 1 && option == 2)
		flag[1] = '+'; // +
	else if (output[0] != '-' && flag[3] == 1 && option == 2)
		flag[1] = ' '; // ' '
	if (flag[1] == '+' || flag[1] == ' ')
		len++;
	if (flag[0])
		ft_putoutput(output, flag);
	while (len++ < flag[2])
	{
		if (flag[4])
			ft_putchar_fd('0', 1, flag);
		else
			ft_putchar_fd(' ', 1, flag);
	}
	if (!flag[0])
		ft_putoutput(output, flag);
}

void	convert_base(int num, int option, int *flag, int base)
{
	char 			*output;
	int				digit;
	unsigned int	n;
	int				i;

	if (num < 0)
		n = UINT_MAX + num + 1;
	else
		n = num;
	output = convert_numtostr(n, base);
	if (output == NULL)
		return ;
	digit = ft_strlen(output);
	i = 0;
	if (option == 1)
	{
		while (i < digit)
		{
			output[i] = ft_toupper(output[i]);
			i++;
		}
	}
	ft_putstr_flag(output, flag, option);
	free(output);
}

void	convert_standard_num(int num, int option, int *flag, int base)
{
	char 			*output;
	int				digit;
	int				i;

	output = ft_itoa_base(num, base);
	if (output == NULL)
		return ;
	digit = ft_strlen(output);
	i = 0;
	ft_putstr_flag(output, flag, option);
	free(output);
}

void	convert_address(void *p, int *flag)
{
	unsigned long long	num;
	char 				*str;
	int					i;
	unsigned long long	div;

	num = (unsigned long long)p;
	str = malloc(sizeof(char) * 19);
	if (str == NULL)
		return ;
	str[18] = '\0';
	i = 17;
	div = 16;
	while (num != 0)
	{
		str[i--] = convert_0x(((num % div) / (div / 16)));
		num -= (num % div);
		div *= 16;
	}
	if (i == 17)
		str[i--] = '0';
	str[i--] = 'x';
	str[i] = '0';
	ft_putstr_flag(&str[i], flag, 0);
	free(str);
}

void	flag_distribute(char *str, va_list ap, int *flag)
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
	else
		return ;
	str++;
	format_distribute(str, ap, flag);
}

void	format_distribute(char *str, va_list ap, int *flag)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(ap, int), 1, flag);
	else if (*str == 's')
		ft_putstr_flag(va_arg(ap, char*), flag, 0);
	else if (*str == 'p')
		convert_address(va_arg(ap, void*), flag);
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
		flag_distribute(str, ap, flag);
}

void	ft_check_percent(char *str, va_list ap, int *flag)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			format_distribute(str, ap, flag);
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
	int		flag[6]; // -, +, num, ' ', 0, count 

    str = ft_strdup(argv);
	flag_init(flag);
	flag[5] = 0;
    if (str == NULL)
        return (0);
    va_start(ap, argv);
    ft_check_percent(str, ap, flag);
    va_end(ap);
	free(str);
	return (flag[5]);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *a = "a";
// 	unsigned int i = 10;

// 	ft_printf("%d\n", 10);
// 	printf("%d\n", 10);
// 	printf("----------\n");
// 	ft_printf("%i\n", 10);
// 	printf("%i\n", 10);
// 	printf("----------\n");
// 	ft_printf("%c\n", 'a');
// 	printf("%c\n", 'a');
// 	printf("----------\n");
// 	ft_printf("%p\n", a);
// 	printf("%p\n", a);
// 	printf("----------\n");
// 	ft_printf("%d\n", ft_printf("%s\n", "42tokyo"));
// 	printf("%d\n", printf("%s\n", "42tokyo"));
// 	printf("----------\n");
// 	ft_printf("%u\n", i);
// 	printf("%u\n", i);
// 	printf("----------\n");
// 	ft_printf("%x\n", 10);
// 	printf("%x\n", 10);
// 	printf("----------\n");
// 	ft_printf("%X\n", 10);
// 	printf("%X\n", 10);
// 	printf("----------\n");
// 	return (0);
// }