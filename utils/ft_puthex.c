/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:09:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:32:36 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
