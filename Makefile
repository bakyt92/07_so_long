NAME = so_long

LIB = ./ft_libft/libft.a

HEADER = so_long.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = so_long.c \
		./src_so_long/ft_error.c \
		./src_so_long/ft_utils.c \
		./src_so_long/ft_check_map.c \
		./src_so_long/ft_push_sprites.c \
		./src_so_long/ft_moves1.c \
		./src_so_long/ft_player_actions.c \
		./src_so_long/ft_map_func1.c

OBJ = $(SRC:%.c= %.o)

MLX_LIB = -lmlx -framework OpenGL -framework AppKit

.PHONY : all clean fclean re

all : libft $(NAME)

libft :
	@MAKE -C ./ft_libft/
	@MAKE bonus -C ./ft_libft/

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ) $(LIB) -o $(NAME) $(MLX_LIB)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)
	@MAKE -C ./ft_libft/ clean

fclean	:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@MAKE -C ./ft_libft/ fclean

re	:	fclean all
