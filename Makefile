NAME = so_long

LIB = ./ft_libft/libft.a
#GNL = ./ft_get_next_line/get_next_line.a

HEADER = so_long.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = so_long.c \
		./src_so_long/ft_error.c \
		./src_so_long/ft_utils.c \
		./src_so_long/ft_get_next_line.c \
		./src_so_long/ft_check_map.c \
		./src_so_long/ft_push_sprites.c \
		./src_so_long/ft_map_func1.c

OBJ = $(SRC:%.c= %.o)

MLX_LIB = -lmlx -framework OpenGL -framework AppKit

.PHONY : all clean fclean re

all : libft $(NAME)

libft :
	@MAKE -C ./ft_libft/
	@MAKE bonus -C ./ft_libft/

#get_next_line :
#	@MAKE -C ./ft_get_next_line/

$(NAME) : $(OBJ) $(HEADER)
#	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ) $(LIB) -o $(NAME) $(MLX_LIB)

# bonus : $(NAME_B)

# $(NAME_B) : $(OBJ_B) $(HEADER_B)
#	cd libft && make bonus && make
# 	$(CC) $(FLAGS) -O2 $(OBJ_B) -o $(NAME_B)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
#	cd libft && make clean
	@rm -f $(OBJ)
	@MAKE -C ./ft_libft/ clean
#	@MAKE -C ./ft_get_next_line/ clean
#	@rm -f $(OBJ_B)

fclean	:	clean
#	cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@MAKE -C ./ft_libft/ fclean
#	@MAKE -C ./ft_get_next_line/ fclean

re	:	fclean all