# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariling <ariling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 08:22:28 by ariling           #+#    #+#              #
#    Updated: 2024/09/06 12:45:05 by ariling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
      ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
      ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
      ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
      ft_printf.c ft_itoa_base.c ft_itoa_unsigned.c ft_itoa_ptr.c \
      handle_string.c handle_int.c handle_unsigned.c handle_hex.c handle_pointer.c handle_percent.c handle_char.c


# Object files
OBJ = $(SRC:.c=.o)

# Library name
NAME = libft.a

# All rule
all: $(NAME)

# Build the library
$(NAME): $(OBJ)
	ar rcs $@ $^

# Rule for compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Full clean rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

