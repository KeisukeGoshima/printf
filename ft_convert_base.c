/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:06:30 by marvin            #+#    #+#             */
/*   Updated: 2022/10/12 15:06:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countdigit_base_unsigned(unsigned long long n, int base)
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

void	setnum_unsigned(long n, int base, char *str, int digit)
{
	unsigned long long	div;
	int					i;

	div = 1;
	i = 0;
	while (i++ < digit)
		div *= base;
	i = 0;
	while (i < digit)
	{
		str[i++] = convert_0x((n % div) / (div / base));
		div /= base;
	}
}

char	*convert_numtostr(unsigned long long n, int base)
{
	int		count;
	char	*str;

	count = countdigit_base_unsigned(n, base);
	if (n == 0)
		count = 1;
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	setnum_unsigned(n, base, str, count);
	str[count] = '\0';
	return (str);
}
