# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 15:32:49 by ssabbah           #+#    #+#              #
#    Updated: 2018/03/21 15:42:32 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC_FILES =	main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))
#LIB = $(addprefix -I,$(LIB_PATH))
INC_DIR = inc
INCLUDES = -I $(INC_DIR)

CC = gcc
FLAGS = -Wall -Wextra

LIBFT = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C libft/
	@ $(CC) $(FLAGS) $(LIBFT) $^ -o $@
	@ echo "\033[32mCompilation done : Checker is ready to be used\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) -c $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@ make -C libft clean
	@ rm -rf $(OBJ)
	@ rm -rf $(OBJ_PATH)
	@ echo "\033[32mCleaning obj\033[0m"

fclean: clean
	@ make -C libft fclean
	@ rm -f $(NAME)
	@ echo "\033[32mCleaning FRACTOL\033[0m"

norm :
	@make -C libft norm
	norminette $(SRC)

re : fclean all
