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

static size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

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
	char		a;
	int			b;
	static int	len;

	len = 0;
	b = ft_strlen(base);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_base(n / b, base);
		len++;
		a = base[n % b];
		write(1, &a, 1);
	}
	return (len);
}
