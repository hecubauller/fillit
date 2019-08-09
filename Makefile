# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huller <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/02 21:49:39 by huller            #+#    #+#              #
#    Updated: 2019/06/05 02:14:28 by huller           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit.c \
		valid.c \
		reader.c \
		node_controls.c \
		solver.c \
		converter.c \
		matrix_writer.c \
		matrix_controls.c \

INCLDS = libft/includes

CFLAGS = -Wall -Wextra -Werror

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): lib
	gcc $(CFLAGS) -I $(INCLDS) -o $(NAME) $(SRCS) -L libft -lft

lib:
	make -C libft

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
