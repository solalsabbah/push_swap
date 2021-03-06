# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 15:32:49 by ssabbah           #+#    #+#              #
#    Updated: 2018/06/12 13:12:32 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT= -Llibft -lft

INC_DIR = inc/

SHARED_SRC =	add_link.c\
				add_end.c\
				param_to_link.c\
				init.c\
				stack_op.c\
				duplicated.c\

CHECKER_SRC =	checker.c\
				operations.c\
				is_sort.c\

PUSHSWAP_SRC = 	push_swap.c\
				median_stack.c\
				bubble_sort.c\
				clustering.c\
				split_stacks.c\
				split_first_stack.c\
				split_second_stack.c\
				bryan.c\
				data_stack.c\
				value_data.c\
				special_cases.c\
				lst_size.c\
			
SHARED_OBJ = $(SHARED_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSHSWAP_OBJ = $(PUSHSWAP_SRC:.c=.o)

VPATH= src/checker/:src/push_swap/:src/shared/ 

#OBJ_PATH = obj/

INCLUDES = -I $(INC_DIR)


all: libft $(CHECKER) $(PUSHSWAP)

libft:
	@make -C libft/

# Executables 

$(CHECKER): $(CHECKER_OBJ) $(SHARED_OBJ) 
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT) 
	@echo "Compiling [$@]"

$(PUSHSWAP): $(PUSHSWAP_OBJ) $(SHARED_OBJ) 
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT) 
	@echo "Compiling [$@]"

# Object files 

$(CHECKER_OBJ): $(CHECKER_SRC)
	@$(CC) -c $^ $(CFLAGS) -I $(INC_DIR) 	
	@echo "Compiling [$^]"

$(SHARED_OBJ): $(SHARED_SRC)
	@$(CC) -c $^ $(CFLAGS) -I $(INC_DIR) 
	@echo "Compiling [$^]"

$(PUSHSWAP_OBJ): $(PUSHSWAP_SRC)
	@$(CC) -c $^ $(CFLAGS) -I $(INC_DIR) 
	@echo "Compiling [$^]"

# Cleaning rules 

clean:
	@rm -f $(PUSHSWAP_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)
	@rm -rf obj
	@echo "Cleaning [$(PUSHSWAP_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)]"	

fclean: clean
	@rm -rf $(CHECKER) $(PUSHSWAP)
	@make fclean -C libft
	@echo "Cleaning [libft checker push_swap]"	

re: fclean all

.PHONY: clean fclean re libft
