/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddrhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:53:03 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/19 14:01:47 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddrhex(unsigned long long addr)
{
	char				*base;
	int					count;

	base = "0123456789abcdef";
	if (addr >= 16)
	{
		count = ft_putaddrhex(addr / 16) + 1;
		ft_putchar_fd(base[addr % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[addr % 16], 1);
		return (1);
	}
	return (count);
}
