/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:07:58 by marvin            #+#    #+#             */
/*   Updated: 2022/10/13 01:07:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_base(int num, int option, int *flag, int base)
{
	char			*output;
	int				digit;
	unsigned int	n;
	int				i;

	n = (unsigned int)num;
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
	if (flag[5] == 1 && base == 16)
		flag[5] = 16 + option;
	ft_putstr_flag(output, flag, option);
	free(output);
}

void	convert_standard_num(int num, int option, int *flag, int base)
{
	char	*output;

	output = ft_itoa_base(num, base);
	if (output == NULL)
		return ;
	ft_putstr_flag(output, flag, option);
	free(output);
}

void	convert_address(unsigned long long p, int *flag)
{
	char	*str;

	str = convert_numtostr(p, 16);
	if (str == NULL)
		return ;
	flag[5] = 15;
	ft_putstr_flag(str, flag, 0);
	free(str);
}
