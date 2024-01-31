# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 02:51:43 by matde-ol          #+#    #+#              #
#    Updated: 2023/11/18 02:14:50 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wextra -Wall
SRC = \
	ft_putstr.c \
	ft_putchar.c \
	ft_strlen.c \
	ft_putnbr.c \
	ft_putnbr_hexa.c \
	ft_put_u_nbr.c \
	ft_hexa_pointer.c \
	ft_printf.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	
re : fclean all
