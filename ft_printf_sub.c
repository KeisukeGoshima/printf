/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:05:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/13 01:05:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putoutput(char *output, int *flag)
{
	if (flag[1] == ' ' || flag[1] == '+')
		ft_putchar_fd(flag[1], 1, flag);
	if (flag[5] == 15)
		ft_putstr_fd("0x", 1, flag);
	if (flag[5] == 16 && output[0] != '0')
		ft_putstr_fd("0x", 1, flag);
	if (flag[5] == 17 && output[0] != '0')
		ft_putstr_fd("0X", 1, flag);
	ft_putstr_fd(output, 1, flag);
}

void	ft_putstr_main(char *output, int *flag, int len)
{
	if (flag[0])
		ft_putoutput(output, flag);
	if (flag[4] && !flag[0] && output[0] == '-')
		ft_putchar_fd('-', 1, flag);
	while (len++ < flag[2])
	{
		if (flag[4] && !flag[0])
			ft_putchar_fd('0', 1, flag);
		else
			ft_putchar_fd(' ', 1, flag);
	}
	if (flag[4] && !flag[0] && output[0] == '-')
		ft_putoutput(&output[1], flag);
	else if (!flag[0])
		ft_putoutput(output, flag);
}

void	ft_putstr_flag(char *output, int *flag, int option)
{
	int	len;

	if (output == NULL)
	{
		ft_putstr_fd("(null)", 1, flag);
		return ;
	}
	len = ft_strlen(output);
	if (output[0] != '-' && flag[1] == 1 && option == 2)
		flag[1] = '+';
	else if (output[0] != '-' && flag[3] == 1 && option == 2)
		flag[1] = ' ';
	if (flag[1] == '+' || flag[1] == ' ')
		len++;
	if (15 <= flag[5] && flag[5] <= 17)
		len += 2;
	ft_putstr_main(output, flag, len);
}

void	ft_putchar_flag(int c, int *flag)
{
	int	len;

	len = 1;
	if (flag[0])
		ft_putchar_fd(c, 1, flag);
	while (len++ < flag[2])
	{
		if (flag[4] && !flag[0])
			ft_putchar_fd('0', 1, flag);
		else
			ft_putchar_fd(' ', 1, flag);
	}
	if (!flag[0])
		ft_putchar_fd(c, 1, flag);
}
