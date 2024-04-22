/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalasut <smalasut@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:10:51 by smalasut          #+#    #+#             */
/*   Updated: 2024/04/22 00:10:51 by smalasut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	n;
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return ((int)n);
}

int	ft_putnbr_base(int n, const char *base)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
			return (ft_putchar('-') + ft_putnbr_base(-n, base));
		else if (n >= 10)
			return (ft_putnbr_base(n / 10, base) + ft_putchar(base[n % 10]));
		else
			return (ft_putchar(base[n % 10]));
	}
}

int	ft_putunbr_base(unsigned int n, const char *base)
{
	unsigned int	b;

	b = (unsigned int)ft_strlen(base);
	if (n >= b)
		return (ft_putunbr_base(n / b, base) + ft_putchar(base[n % b]));
	else
		return (ft_putchar(base[n % b]));
}

int	ft_putlnbr_base(unsigned long long n, const char *base)
{
	if (n == 0)
		return (ft_putstr("(nil)"));
	else
	{
		if (n >= 16)
			return (ft_putlnbr_base(n / 16, base) + ft_putchar(base[n % 16]));
		else
			return (ft_putstr("0x") + ft_putchar(base[n % 16]));
	}
}
