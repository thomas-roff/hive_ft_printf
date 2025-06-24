/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:10:12 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 13:23:56 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <float.h>

// Custom implementation of library printf function, handling flags cspdiuxX%
int		ft_printf(const char *format, ...);
// Writes a hex to standard output, custom charsets are accepted via the hex
// variable
int		ft_puthex(unsigned long nbr, const char *hex);
// Feeds into ft_puthex and allows user to specify whether traditional hex
// charset is uppercase or lowercase
// int		hexcharset(unsigned long nbr, int isuphex);
// Feeds into hexcharset and ft_puthex and handles inputs from printf
// int		hexhandler(va_list args);
// Feeds into hexcharset and ft_puthex and handles inputs from printf
int		ft_putptr(va_list args);
// Does what it says
size_t	ft_strlen(const char *s);
// Writes a character to the standard output
int		ft_putchar(char c);
// Writes a string to the standard output
int		ft_putstr(const char *s);
// Writes an integer to the standard output
int		ft_putnbr(int n);
// Writes an unisgned integer to the standard output
int		ft_putuin(unsigned int u);

#endif
