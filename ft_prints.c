/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:17:18 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/22 14:19:21 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(va_list pi)
{
	char	c;

	c = va_arg(pi, int);
	return (write(1, &c, 1));
}

int	ft_prints(va_list pi)
{
	char	*str;

	str = va_arg(pi, char *);
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, str, ft_strlen(str)));
}

int	ft_printp(va_list pi)
{
	int	n;

	n = write(1, "0x", 2);
	n += ft_putnbr_base((unsigned long)va_arg(pi, void *), "0123456789abcdef");
	return (n);
}

int	ft_printd(va_list pi)
{
	int		nb;
	char	*str;
	int		size;

	nb = va_arg(pi, int);
	str = ft_itoa(nb);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_printu(va_list pi)
{
	return (ft_putnbr_base((unsigned int)va_arg(pi, int), "0123456789"));
}
