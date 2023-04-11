# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 00:51:40 by ichiro            #+#    #+#              #
#    Updated: 2023/04/11 15:25:01 by imisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = includes/fdf.h

CFLAGS = -g -I include

LFLAGS = -lglfw3 -framework Cocoa -framework OpenGl -framework IOKit

cc = gcc 
# -Wall -Werror -Wextra

MLX = lib/MLX42/build/libmlx42.a
LIBFT = lib/libft/libft.a

OBJS_DIR = objs
SRC_DIR = src

INC := -I $(INCLUDE_DIR)

SRCS = main.c print.c read_map.c draw.c vector.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all:  $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(cc) $(CFLAGS) $(INC) -I -c -o $@ $<

$(MLX):

mlx : 

$(LIBFT):
	@$(MAKE) -C lib/libft

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(cc) $(CFLAGS) $(INC) -I $^ -o $(NAME) $(LFLAGS)

run: all
	./fdf test.txt

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