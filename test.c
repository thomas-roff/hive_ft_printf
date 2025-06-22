/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:39:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/06/22 20:51:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		return (ft_printf(argv[1]), 0);
	if (argc > 2)
		ft_printf(argv[1], -1);
	return (0);
}
