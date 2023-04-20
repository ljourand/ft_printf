/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:28:17 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/19 13:32:59 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	size_t	len;
	int		count;

	count = 1;
	len = ft_strlen(base);
	if (nb >= (unsigned long long)len)
	{
		count += ft_putnbr_base(nb / len, base);
	}
	ft_putchar_fd(base[nb % len], 1);
	return (count);
}
