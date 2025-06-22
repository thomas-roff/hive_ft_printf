/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:17:47 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/22 20:49:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*sc;
	char	cc;

	sc = (char *)s;
	cc = (char)c;
	if (cc == '\0')
		return (sc + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (*sc == cc)
			return (sc);
		sc++;
	}
	return (NULL);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		write(1, &*s, 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	size;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	size = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		size++;
	}
	if (n > 9)
		size += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	size++;
	return (size);
}

int	argcount(const char *format)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			count++;
		format++;
	}
	return (count);
}

#include <stdio.h>

int	flagchr(const char *format, int argnum)
{
	int	i;

	i = ft_strlen(format) - 1;
	while (i >= 0)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			argnum--;
			if (argnum == 0)
				return (format[i + 1]);
		}
		i--;
	}
	return (-1);
}

int ft_puthex(unsigned int nbr, const char *hex)
{
	int count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, hex);
	ft_putchar(hex[nbr % 16]);
	count++;
	return (count);
}

int	hexcharset(unsigned int nbr, int isuphex)
{
	int	count;

	if (isuphex)
		count = ft_puthex(nbr, "0123456789ABCDEF");
	else
		count = ft_puthex(nbr, "0123456789abcdef");
	return (count);
}

int	ft_hex(va_list args, int isuphex, int isptr)
{
	int	count;

	if (isptr)
	{
		count = ft_putstr("0x");
		count += hexcharset((unsigned long)va_arg(args, void *), isuphex);
	}
	else
		count = hexcharset(va_arg(args, unsigned int), isuphex);
	return (count);
}

int	putarg(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar((char)va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char*));
	if (c == 'p')
		count = ft_hex(args, 0, 1);
	// if (c == 'd')
		// count = ft_putstr(va_arg(args, char*), 1);
	if (c == 'i')
		count = ft_putnbr(va_arg(args, int));
	// if (c == 'u')
		// count = ft_putchar((char)va_arg(args, int), 1);
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
	// int		argnum;
	int		count;
	int		len;

	len = ft_strlen(format);
	// if (!ft_strchr(format, '%'))
	// 	return(ft_putstr(format, 1), len);
	va_start(args, format);
	// argnum = argcount(format);
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
			// if (format[i + 1] == '%')
			// 	count += ft_putchar('%', 1);
			// else
			// 	count += putarg(format, args, argnum--);
			// i += 2;
	}
	va_end(args);
	printf("\nBytes printed: %i\n", count);
	return (count);
}
