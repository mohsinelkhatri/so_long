# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 14:11:57 by melkhatr          #+#    #+#              #
#    Updated: 2025/08/04 17:44:32 by melkhatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CC      = cc
FLAGS   = -Wall -Wextra -Werror

MLX_DIR = libs/minilibx
SRC_DIRS = . validate_map start_game utils libs/get_next_line libs/ft_printf

SRC = \
	main.c \
	parse_map.c \
	validate_map/validate_map.c \
	validate_map/check_characters.c \
	validate_map/check_shape.c \
	validate_map/check_border.c \
	validate_map/check_way.c \
	start_game/start_game.c \
	start_game/fill_textures.c \
	start_game/events.c \
	utils/error.c \
	utils/free_map.c \
	utils/map_width.c \
	utils/ft_atoi.c \
	freeall.c \
	utils/ft_split.c \
	utils/map_height.c \
	utils/find_coords.c \
	utils/is_all_collected.c \
	libs/get_next_line/get_next_line.c \
	libs/get_next_line/get_next_line_utils.c \
	libs/ft_printf/ft_printf.c \
	libs/ft_printf/ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx_Linux.a $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -o $(NAME)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
