NAME = fillit

SRCS = 	fillit.c \
		valid.c \
		reader.c \
		node_controls.c \
		solver.c \
		converter.c \

OBJS = $(SRCS:.c=.o)

INCLDS = libft/includes

CFLAGS = -g -Wall -Wextra -Werror

LIB = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	gcc -c $(CFLAGS) -I $(INCLDS) $(SRCS)
	gcc $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

norm:
	norminette $(SRCS)
