/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:39:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/14 12:57:51 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
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
	cf = ft_printf("FT_ minus int: %i\n", -1);
	cl = printf("LIB minus int: %i\n", -1);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	ft_printf("FT_ minus str: ");
	cf = ft_printf("-1");
	printf("\n");
	printf("LIB minus str: ");
	cl = printf("-1");
	printf("\n");
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	p = NULL;
	ft_printf("\n");
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
	ft_printf("\n");
	ft_printf("INVALID SPECIFIER TESTS\n");
	cf = ft_printf("FT_ f: %z\n", -1);
	cl = printf("LIB f: %z\n", -1);
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	ft_printf("\n");
	ft_printf("SINGLE %% TEST\n");
	cf = ft_printf("%");
	cl = printf("%");
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	ft_printf("\n");
	ft_printf("LONELY %% TEST\n");
	cf = ft_printf("I am % here\n");
	cl = printf("I am % here\n");
	ft_printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	ft_printf("\n");
	ft_printf("TRAILING %% TEST\n");
	cf = ft_printf("I am here %");
	ft_printf("\n");
	cl = printf("I am here %");
	printf("\n");
	printf("RETURNS FT_: %i LIB: %i\n", cf, cl);
	return (0);
}
