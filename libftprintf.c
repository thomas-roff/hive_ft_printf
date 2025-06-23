/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:17:47 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/23 22:07:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putarg(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar((char)va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count = ft_hex(args, 0, 1);
	if (c == 'd')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_putuin(va_arg(args, unsigned int));
	if (c == 'x')
		count = ft_hex(args, 0, 0);
	if (c == 'X')
		count = ft_hex(args, 1, 0);
	return (count);
}

int	checkflag(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (putarg(c, args));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len;

	len = ft_strlen(format);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += checkflag(*format++, args);
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
