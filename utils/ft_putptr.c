/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:04:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:36:37 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(va_list args)
{
	int				count;
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	count += ft_puthex(ptr, "0123456789abcdef");
	if (count < 0)
		return (-1);
	return (count);
}
