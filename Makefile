# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 13:29:47 by wlin              #+#    #+#              #
#    Updated: 2017/08/19 14:20:13 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a

LIB_DIR = libft/
SRC_DIR = src/
BUILD_DIR = build/
INC_DIR = include/

SRC = \
lem_in \
parse_map \
constructors


SRC_PATH = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJ_PATH = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC)))

all:

$(NAME): $(OBJ_PATH) $(LIBFT)
	@$(CC) $(CFLAGS) -g $(OBJ_PATH) -o $@ -I libft/libft.h -L./libft -lft
	@echo "\033[32mExecutable \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -rf $(BUILD_DIR);
	@cd libft && $(MAKE) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
