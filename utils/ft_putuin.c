/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:05:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:33:09 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putuin(unsigned int u)
{
	int	count;

	count = 0;
	if (u > 9)
		count += ft_putuin(u / 10);
	if (!ft_putchar((u % 10) + '0'))
		return (-1);
	count++;
	return (count);
}
