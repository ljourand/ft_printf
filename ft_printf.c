/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:29:35 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/25 11:40:56 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printx(va_list pi)
{
	return (ft_putnbr_base((unsigned int)va_arg(pi, int), "0123456789abcdef"));
}

static int	ft_printupperx(va_list pi)
{
	return (ft_putnbr_base((unsigned int)va_arg(pi, int), "0123456789ABCDEF"));
}

static void	ft_init_array(int (*f[8])(va_list))
{
	f[0] = ft_printc;
	f[1] = ft_prints;
	f[2] = ft_printp;
	f[3] = ft_printd;
	f[4] = ft_printd;
	f[5] = ft_printu;
	f[6] = ft_printx;
	f[7] = ft_printupperx;
}

static int	iterate(const char *format, va_list pi, int (*f[8])(va_list))
{
	int		count;
	char	*charset;
	int		index;

	charset = "cspdiuxX";
	count = 0;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			index = ft_strchr(charset, *format) - charset;
			if (index < 0)
				count += write(1, format, 1);
			else
				count += f[index](pi);
		}
		else if (*format != '%')
			count += write(1, format, 1);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		(*functions[8])(va_list);

	va_list(pi);
	va_start(pi, format);
	ft_init_array(functions);
	count = iterate(format, pi, functions);
	va_end(pi);
	return (count);
}
