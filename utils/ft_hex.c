/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:09:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/23 21:51:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_puthex(unsigned long nbr, const char *hex)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, hex);
	ft_putchar(hex[nbr % 16]);
	count++;
	return (count);
}

int	hexcharset(unsigned long nbr, int isuphex)
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
	int				count;
	unsigned long	hex;

	if (isptr)
	{
		hex = (unsigned long)va_arg(args, void *);
		if (!hex)
			return (ft_putstr("(nil)"));
		count = ft_putstr("0x");
		count += hexcharset(hex, isuphex);
	}
	else
	{
		hex = va_arg(args, unsigned int);
		count = hexcharset(hex, isuphex);
	}
	return (count);
}
