# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 17:29:33 by laroges           #+#    #+#              #
#    Updated: 2023/10/14 21:42:21 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
	ft_argv.c \
	ft_init.c \
	ft_initialisation.c \
	ft_push.c \
	push_swap.c \
	ft_radix.c \
	ft_reverse_rotate.c \
	ft_rotate.c \
	ft_sort.c \
	ft_sort_small.c \
	ft_sort_small_bis.c \
	ft_stack.c \
	ft_sub_fonction.c \
	ft_swap.c \
	utils.c

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

OBJ =	$(SRC:.c=.o)

NAME =	./push_swap

NAMELIBFT =	libft.a

INCLUDES =	./libft/

all: $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDES) $(NAMELIBFT) -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
