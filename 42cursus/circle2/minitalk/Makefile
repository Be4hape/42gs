# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: si-park <si-park@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:58:20 by si-park           #+#    #+#              #
#    Updated: 2025/07/18 11:35:12 by si-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iprintf

PRINTF_DIR  = printf
LIBFT_DIR   = $(PRINTF_DIR)/libft

CLIENT   = client
SERVER   = server

CLIENT_SRC   = client.c 
SERVER_SRC   = server.c
LIBFT_SRC    = $(wildcard $(LIBFT_DIR)/*.c)
FT_PRINTF_SRC = $(PRINTF_DIR)/ft_handlers.c \
                $(PRINTF_DIR)/ft_hexutil.c \
                $(PRINTF_DIR)/ft_printf.c

CLIENT_OBJ   = $(CLIENT_SRC:.c=.o)
SERVER_OBJ   = $(SERVER_SRC:.c=.o)
PRINTF_OBJ   = $(LIBFT_SRC:.c=.o) $(FT_PRINTF_SRC:.c=.o)

all: $(PRINTF_OBJ) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(SERVER_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
