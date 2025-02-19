# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:07:55 by si-park           #+#    #+#              #
#    Updated: 2025/02/19 12:30:18 by si-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

PRINTF_SRCS = ft_printf.c ft_handlers.c ft_hexutil.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(PRINTF_OBJS)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(PRINTF_OBJS)
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PRINTF_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re