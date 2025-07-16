/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:39:54 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:33:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = ft_strlen(s);
	if (write(1, s, count) < 0)
		return (-1);
	return (count);
}

int	ft_putuint(unsigned int n)
{
	int		count;
	int		i;
	char	*buffer;

	if (n >= 0 && n < 10)
		return (ft_putchar(n + '0'));
	buffer = malloc(sizeof(char) * 10);
	if (!buffer)
		return (-1);
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
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

int	ft_putnbr(int n)
{
	int	count;
	int	temp;

	if (n == -2147483648)
	{
		if (!ft_putstr("-2147483648"))
			return (-1);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		if (!ft_putchar('-'))
			return (-1);
		n = -n;
		count = 1;
	}
	temp = ft_putuint((unsigned int)n);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
