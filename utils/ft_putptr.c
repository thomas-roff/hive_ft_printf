/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:04:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 13:22:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int ft_putptr(va_list args)
{
	int				count;
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}
