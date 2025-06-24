# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 13:18:58 by thblack-          #+#    #+#              #
#    Updated: 2025/06/24 16:34:23 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c utils/ft_puthex.c utils/ft_putuin.c \
			utils/ft_putptr.c utils/ft_printf_utils.c
OBJECTS = $(SOURCES:.c=.o) 
HEADER = ft_printf.h
NAME = libftprintf.a

ar: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean ar

.PHONY: ar clean fclean re
