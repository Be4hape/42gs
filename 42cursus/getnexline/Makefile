# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 14:54:26 by si-park           #+#    #+#              #
#    Updated: 2025/02/23 14:55:41 by si-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifdef
NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

$(NAME): $(SRC)
 $(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(SRC) -o $(NAME)

all: $(NAME)

clean:
 fclean:
 rm -f $(NAME)

re: fclean all

endif