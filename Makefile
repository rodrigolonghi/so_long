# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 18:12:25 by rfelipe-          #+#    #+#              #
#    Updated: 2021/09/16 19:25:37 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
FLAGS_TESTE = -g -Wall -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
#-g3 -fsanitize=address -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = libft/libft.a

MLX_DIR = mlx_linux
MLX = mlx_linux/libmlx.a

SRC_DIR = src/mandatory
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/start_game.c \
		$(SRC_DIR)/load_img.c \
		$(SRC_DIR)/throw_error.c \
		$(SRC_DIR)/check_params.c \
		$(SRC_DIR)/check_map.c \
		$(SRC_DIR)/put_images.c \
		$(SRC_DIR)/key_hook.c \
		$(SRC_DIR)/close_game.c \
		$(SRC_DIR)/check_movement.c

BONUS_SRC_DIR = src/bonus
BONUS_SRC = $(BONUS_SRC_DIR)/main_bonus.c \
			$(BONUS_SRC_DIR)/start_game_bonus.c \
			$(BONUS_SRC_DIR)/load_img_bonus.c \
			$(BONUS_SRC_DIR)/throw_error_bonus.c \
			$(BONUS_SRC_DIR)/check_params_bonus.c \
			$(BONUS_SRC_DIR)/check_map_bonus.c \
			$(BONUS_SRC_DIR)/put_images_bonus.c \
			$(BONUS_SRC_DIR)/key_hook_bonus.c \
			$(BONUS_SRC_DIR)/close_game_bonus.c \
			$(BONUS_SRC_DIR)/check_movement_bonus.c \
			$(BONUS_SRC_DIR)/walk_animation_bonus.c

INCLUDE_DIR = includes
INCLUDE = $(INCLUDE_DIR)/so_long.h
BONUS_INCLUDE = $(INCLUDE_DIR)/so_long_bonus.h

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ_DIR = objs_bonus
BONUS_OBJ = $(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

APP_DIR = app

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	mkdir -p $(APP_DIR)
	$(CC) -lm $(OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) -o $(APP_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS_TESTE) -I$(INCLUDE_DIR) -o $@ $<

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_INCLUDE)
	mkdir -p $(BONUS_OBJ_DIR)
	$(CC) -c $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(APP_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

bonus: fclean $(LIBFT) $(MLX) $(BONUS_OBJ)
	mkdir -p $(APP_DIR)
	$(CC) -lm $(BONUS_OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) -o app/$(NAME)
