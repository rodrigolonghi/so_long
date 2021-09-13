# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 18:12:25 by rfelipe-          #+#    #+#              #
#    Updated: 2021/09/13 16:01:26 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang
FLAGS = -g -Wall -Wextra -Werror
FLAGS_TESTE = -g -Wall -Wextra
MLX_FLAGS = -lmlx -lXext -lX11

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

MLX_DIR = mlx_linux
MLX = mlx_linux/libmlx.a

SRC_DIR = srcs
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/start_game.c \
		$(SRC_DIR)/load_img.c \
		$(SRC_DIR)/throw_error.c \
		$(SRC_DIR)/check_params.c \
		$(SRC_DIR)/check_map.c \
		$(SRC_DIR)/put_images.c \
		$(SRC_DIR)/key_hook.c \
		$(SRC_DIR)/close_game.c

INCLUDE_DIR = includes
INCLUDE = includes/so_long.h

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) -lm $(OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS_TESTE) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

run: all
	./$(NAME)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
