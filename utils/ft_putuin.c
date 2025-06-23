/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:05:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/23 21:05:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putuin(unsigned int u)
{
	int	count;

	count = 0;
	if (u > 9)
		count += ft_putuin(u / 10);
	ft_putchar((u % 10) + '0');
	count++;
	return (count);
}
