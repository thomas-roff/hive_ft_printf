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
	int		count;
	int		i;
	char	*buffer;

	if (nbr >= 0 && nbr < 16)
		return (ft_putchar(hex[nbr]));
	buffer = malloc(sizeof(char) * 8);
	if (!buffer)
		return (-1);
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	count = i;
	while (i > 0)
	{
		if (!ft_putchar(buffer[--i]))
			return (-1);
	}
	free(buffer);
	return (count);
}
