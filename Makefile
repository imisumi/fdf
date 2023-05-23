# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 00:51:40 by ichiro            #+#    #+#              #
#    Updated: 2023/05/23 16:38:26 by imisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = includes/fdf.h

CFLAGS = -g -I include

LFLAGS = -lglfw3 -framework Cocoa -framework OpenGl -framework IOKit

cc = gcc 
# -Wall -Werror -Wextra

UNAME := $(shell uname -m)

ifeq ($(UNAME), x86_64)
	LFLAGS = -lglfw3 -framework Cocoa -framework OpenGl -framework IOKit
else
	LFLAGS = -lglfw -framework Cocoa -framework OpenGl -framework IOKit
endif

MLX = lib/MLX42/build/libmlx42.a
LIBFT = lib/libft/libft.a

OBJS_DIR = objs
SRC_DIR = src

INC := -I $(INCLUDE_DIR)

SRCS = main.c \
		read_map.c read_map_utils.c \
		draw.c \
		vector_1.c vector_2.c vector_3.c\
		transform_grid_1.c transform_grid_2.c \
		ft_font.c ft_font_utils.c \
		menu_1.c menu_2.c \
		transform.c \
		color_picker.c color_picker_2.c \
		color.c color_utils.c \
		convert_color.c \
		set_value.c \
		key_hook.c cursor_hook.c cursor_hook_2.c \
		projection.c \
		draw_line.c \
		p2_float_to_string.c
 
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(cc) $(CFLAGS) $(INC) -I -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C lib/libft

$(MLX):
	cd ./lib/MLX42 && cmake -DBUILD_TESTS=ON -B build && cmake --build build --parallel

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(cc) $(CFLAGS) $(INC) -I $^ -o $(NAME) $(LFLAGS)

run: all
	./fdf test.txt
	
git:
	git add .
	git commit -m "$(m)"
	git push

clean:
	@rm -rf $(OBJS_DIR)
	@rm -f libmlx.dylib
	@make clean -C lib/libft

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re