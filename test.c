/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:39:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/23 22:11:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		a;
	void	*p;
	char	*str;
	int		cf;
	int		cl;

	p = &a;
	str = NULL;
	ft_printf("VALID DATA TESTS\n");
	cf = ft_printf("FT_ char: %c\n", 'c');
	cl = printf("LIB char: %c\n", 'c');
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ string: %s\n", "str");
	cl = printf("LIB string: %s\n", "str");
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ void*: %p\n", p);
	cl = printf("LIB void*: %p\n", p);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ decimal: %d\n", 69);
	cl = printf("LIB decimal: %d\n", 69);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ int: %i\n", 69);
	cl = printf("LIB int: %i\n", 69);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ unsigned int: %u\n", 4294967295);
	cl = printf("LIB unsigned int: %u\n", 4294967295);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ lowhex: %x\n", 69);
	cl = printf("LIB lowhex: %x\n", 69);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ highhex: %X\n", 4294967295);
	cl = printf("LIB highhex: %X\n", 4294967295);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ percent: %%\n");
	cl = printf("LIB percent: %%\n");
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	ft_printf("\n");
	p = NULL;
	ft_printf("INVALID DATA TESTS\n");
	cf = ft_printf("FT_ char: %c\n", -1);
	cl = printf("LIB char: %c\n", -1);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ string: %s\n", str);
	cl = printf("LIB string: %s\n", str);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ void*: %p\n", p);
	cl = printf("LIB void*: %p\n", p);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ decimal: %d\n", 2147483648);
	cl = printf("LIB decimal: %d\n", 2147483648);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ int: %i\n", 2147483648);
	cl = printf("LIB int: %i\n", 2147483648);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ unsigned int: %u\n", 4294967296);
	cl = printf("LIB unsigned int: %u\n", 4294967296);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ lowhex: %x\n", 2147483648);
	cl = printf("LIB lowhex: %x\n", 2147483648);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ highhex: %X\n", 4294967296);
	cl = printf("LIB highhex: %X\n", 4294967296);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	cf = ft_printf("FT_ highhex: %p\n", 4294967296);
	cl = printf("LIB highhex: %p\n", 4294967296);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	return (0);
}
