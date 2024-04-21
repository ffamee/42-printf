/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalasut <smalasut@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:32:01 by smalasut          #+#    #+#             */
/*   Updated: 2024/04/21 17:32:01 by smalasut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC "0123456789"
# define HLOW "0123456789abcdef"
# define HUP "0123456789ABCDEF"

int	ft_printf(const char *str, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(int n, const char *base);

#endif
