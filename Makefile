# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 15:32:49 by ssabbah           #+#    #+#              #
#    Updated: 2018/04/10 13:28:36 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap

CC = gcc
FLAGS = -Wall -Wextra
LIBFT = -L./libft -lft

SHARED_SRC =	solve.c\
				list_op.c\
				print_stacks.c\
				init.c\

CHECKER_SRC = checker.c\

PUSHSWAP_SRC = push_swap.c\

SHARED_OBJ = $(SHARED_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSHSWAP_OBJ = $(PUSHSWAP_SRC:.c=.o)

VPATH=src/checker/:src/push_swap/:src/shared/ 

OBJ_PATH = obj/

INC_DIR = inc/
INCLUDES = -I $(INC_DIR)


all: $(CHECKER) $(PUSHSWAP)
	@ make -C libft/

$(CHECKER): $(CHECKER_OBJ) $(SHARED_OBJ)
	@ $(CC) $(FLAGS) $(LIBFT) $^ -o $@
	@ echo "\033[32mCompilation done : checker is ready to be used\033[0m"

$(PUSHSWAP): $(PUSHSWAP_OBJ) $(SHARED_OBJ)
	@ $(CC) $(FLAGS) $(LIBFT) $^ -o $@
	@ echo "\033[32mCompilation done : push_swap is ready to be used\033[0m"

$(SHARED_OBJ)%.o:$(SHARED_SRC)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) -c $(FLAGS) $(INCLUDES) -o $@ -c $<
	
$(CHECKER_OBJ)%.o:$(CHECKER_SRC)%.c
	@ $(CC) -c $(FLAGS) $(INCLUDES) -o $@ -c $<

$(PUSHSWAP_OBJ)%.o:$(PUSHSWAP_SRC)%.c
	@ $(CC) -c $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@ make -C libft clean
	@ rm -rf $(SHARED_OBJ) $(CHECKER_OBJ) $(PUSHSWAP_OBJ)
	@ rm -rf $(OBJ_PATH)
	@ echo "\033[32mCleaning obj\033[0m"

fclean: clean
	@ make -C libft fclean
	@ rm -f $(CHECKER) $(PUSHWAP)
	@ echo "\033[32mCleaning executables\033[0m"

norm :
	@make -C libft norm
	norminette $(SRC)

re : fclean all
