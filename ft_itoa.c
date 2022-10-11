/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoshima <kgoshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:31:02 by kgoshima          #+#    #+#             */
/*   Updated: 2022/10/10 11:12:00 by kgoshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	countdigit(long n, int base)
{
	int	digit;

	digit = 0;
	while (n != 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}

char	convert_0x(int num)
{
	if (num <= 9)
		return (num + '0');
	else
		return (num - 10 + 'a');
}

void	setnum(long n, int base, char *str, int sign)
{
	int		digit;
	long	div;
	int		i;

	digit = countdigit_base(n, base);
	div = 1;
	i = 0;
	while (i++ < digit)
		div *= base;
	i = sign;
	while (i < digit + sign)
	{
		str[i++] = convert_0x((n % div) / (div / base));
		div /= base;
	}
	if (sign)
	{
		if (digit)
			str[0] = '-';
		else
			str[0] = '0';
	}
}

char	*ft_itoa_base(int n, int base)
{
	int		count;
	long	num;
	int		sign;
	char	*str;

	sign = 0;
	num = n;
	if (num <= 0)
	{
		sign = 1;
		num *= -1;
	}
	count = countdigit_base(num, base);
	str = malloc(sizeof(char) * (count + sign + 1));
	if (str == NULL)
		return (NULL);
	setnum(num, base, str, sign);
	str[count + sign] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str;

// 	str = ft_itoa(-1);
// 	printf("%s", str);
// 	return (0);
// }