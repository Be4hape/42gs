# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: si-park <si-park@student.42gyeongsan.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 20:14:48 by si-park           #+#    #+#              #
#    Updated: 2024/10/05 20:56:47 by si-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
      ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
      ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

# 기본 규칙: libft.a를 만든다
all: $(NAME)

# libft.a를 만들기 위한 규칙
$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

# .o 파일을 만들기 위한 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 깨끗하게 정리하는 규칙
clean:
	rm -f $(OBJ)

# libft.a와 .o 파일을 모두 제거하는 규칙
fclean: clean
	rm -f $(NAME)

# 다시 빌드하는 규칙
re: fclean all
