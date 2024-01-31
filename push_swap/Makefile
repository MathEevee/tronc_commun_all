# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:10:49 by matde-ol          #+#    #+#              #
#    Updated: 2023/12/26 10:11:16 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc

DIR_LIB = Libft/
DIR_INC = Libft/
DIR_SRC = src/
DIR_OBJ = obj/

CFLAGS = -Werror -Wextra -Wall
IFLAGS = -I$(DIR_INC)
LFLAGS = -L$(DIR_LIB) -lft

SRC = \
		actions_double_stack.c \
		actions_stack_a.c \
		actions_stack_b.c \
		calc_utils.c \
		check_input.c \
		create_lst.c \
		init_stack_a.c \
		init_stack_b.c \
		push.c \
		push_swap.c \
		from_b_to_a.c \
		rotate.c \
		swap.c \
		sort_a.c \
		from_a_to_b.c \
		find_solution.c \
		rotate_direction.c \
		calc_cost.c \
		rotate_stack_a.c \
		free_stack.c \
		check_stack_a.c \
		check_overflow.c
		
		
LIBFT = $(DIR_LIB)/libft.a

OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(LIBFT) :
	make -C $(DIR_LIB) bonus

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $@

$(DIR_OBJ)%.o : $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -C $(DIR_LIB) clean
	rm -rf $(DIR_OBJ)

fclean: clean
	make -C $(DIR_LIB) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
