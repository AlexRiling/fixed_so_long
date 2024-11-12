# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourusername <yourusername@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:00:00 by yourusername      #+#    #+#              #
#    Updated: 2024/04/27 12:00:00 by yourusername     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

# Project Name
NAME = so_long

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx-linux

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Directories
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

# Source Files
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/map_parser.c \
      $(SRC_DIR)/map_parser_utils.c \
      $(SRC_DIR)/map_utils.c \
      $(SRC_DIR)/validate_map.c \
      $(SRC_DIR)/game.c \
      $(SRC_DIR)/graphics.c \
      $(SRC_DIR)/graphics_utils.c \
      $(SRC_DIR)/handle_keypress.c \
      $(SRC_DIR)/handle_close.c \
      $(SRC_DIR)/clear_data.c

# Object Files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

# Default Target
all: $(NAME)

# Compile and Link the Project
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile Source Files to Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean Object Files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

# Fully Clean the Project
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild the Project
re: fclean all

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all clean fclean re

