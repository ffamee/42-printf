/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalasut <smalasut@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:33:40 by smalasut          #+#    #+#             */
/*   Updated: 2024/04/21 17:33:40 by smalasut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'i' || format == 'd')
		return (ft_putnbr_base(va_arg(arg, int), DEC));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(arg, unsigned int), DEC));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int), HUP));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int), HLOW));
	else if (format == 'p')
		return (ft_putstr("0x")
			+ ft_putnbr_base(va_arg(arg, unsigned long long), HLOW));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		printlen;
	va_list	arg;

	printlen = 0;
	va_start(arg, str);
	while (str)
	{
		if (*str == '%')
		{
			str++;
			printlen += ft_format(*str, arg);
		}
		else
			printlen += ft_putchar(*str);
		str++;
	}
	return (printlen);
}
