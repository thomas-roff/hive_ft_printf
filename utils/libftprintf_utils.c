/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:39:54 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/23 22:05:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_strlen(const char *s)

{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
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
	int	count;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		count = ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	count++;
	return (count);
}
