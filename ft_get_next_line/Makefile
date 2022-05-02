NAME = get_next_line.a

LIB = ../ft_libft/libft.a

SRC = get_next_line.c get_next_line_utils.c

CC = gcc

HEADER = get_next_line.h

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -O2 $(OBJ) $(LIB) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
