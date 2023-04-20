/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:30:17 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/22 14:18:41 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_base(unsigned long long nb, char *base);
int		ft_printc(va_list pi);
int		ft_prints(va_list pi);
int		ft_printp(va_list pi);
int		ft_printd(va_list pi);
int		ft_printu(va_list pi);

#endif