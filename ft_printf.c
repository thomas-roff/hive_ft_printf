/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:17:47 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:32:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar((char)va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count = ft_putptr(args);
	if (c == 'd')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_putuin(va_arg(args, unsigned int));
	if (c == 'x')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
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
		return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

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
