/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:37:50 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 22:37:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd, int *flag)
{
	if (fd < 0)
		return ;
	flag[6] += write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd, int *flag)
{
	if (s == NULL || fd < 0)
		return ;
	flag[6] += write(fd, s, ft_strlen(s));
}