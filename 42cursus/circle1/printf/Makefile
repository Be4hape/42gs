# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:07:55 by si-park           #+#    #+#              #
#    Updated: 2025/01/14 16:41:18 by si-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF_SRCS = ft_printf.c ft_hexutil.c
LIBFT_SRCS = libft/ft_itoa.c libft/ft_strlen.c libft/ft_strdup.c \
             libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
             libft/ft_memmove.c libft/ft_memcpy.c

SRCS = $(PRINTF_SRCS) $(LIBFT_SRCS)

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h libft/libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
