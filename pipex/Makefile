# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:10:49 by matde-ol          #+#    #+#              #
#    Updated: 2024/01/27 19:09:46 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc

DIR_LIB = Libft/
DIR_INC = Libft/
DIR_SRC = src/
DIR_OBJ = obj/

CFLAGS = -Werror -Wextra -Wall -g
IFLAGS = -I$(DIR_INC)
LFLAGS = -L$(DIR_LIB) -lft -lm

SRC = \
		pipex.c \
		error.c \
		clear_data.c \
		lst_dir.c \
		init_data.c \
		exec_cmd.c
		
LIBFT = $(DIR_LIB)/libft.a

OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(LIBFT) :
	make bonus -C $(DIR_LIB)

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
