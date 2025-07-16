/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:10:12 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/24 16:36:16 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <float.h>

// Custom implementation of library printf function, handling flags cspdiuxX%
int		ft_printf(const char *format, ...);
// Checks for specifiers cspdiuxX% in ft_printf
int		ft_checkspec(char c, va_list args);
// Calls various put... functions depending on whicha specifier was found
// in ft_printf
int		ft_putarg(char c, va_list args);
// Writes a hex to standard output, custom charsets are accepted via the hex
// variable
int		ft_puthex(unsigned long nbr, const char *hex);
// Writes a pointer in the format 0x[HEX] to standard output. Function calls
// ft_puthex and handles input from printf
int		ft_putptr(va_list args);
// Writes a character to the standard output
int		ft_putchar(char c);
// Writes a string to the standard output
int		ft_putstr(const char *s);
// Writes an integer to the standard output
int		ft_putnbr(int n);
// Writes an unisgned integer to the standard output
int		ft_putuint(unsigned int u);
// Does what it says
size_t	ft_strlen(const char *s);

#endif
