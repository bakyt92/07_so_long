NAME = so_long

BONUS = so_long_bonus

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

SRC_BONUS = so_long_bonus.c \
		./src_so_long_bonus/ft_error_bonus.c \
		./src_so_long_bonus/ft_utils_bonus.c \
		./src_so_long_bonus/ft_check_map_bonus.c \
		./src_so_long_bonus/ft_push_sprites_bonus.c \
		./src_so_long_bonus/ft_moves1_bonus.c \
		./src_so_long_bonus/ft_player_actions_bonus.c \
		./src_so_long_bonus/ft_map_func1_bonus.c \
		./src_so_long_bonus/ft_animation_bonus.c

OBJ = $(SRC:%.c= %.o)

OBJ_BONUS = $(SRC_BONUS:%.c= %.o)

MLX_LIB = -lmlx -framework OpenGL -framework AppKit

.PHONY : all bonus clean fclean re

all : libft $(NAME)

libft :
	@MAKE -C ./ft_libft/
	@MAKE bonus -C ./ft_libft/

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ) $(LIB) -o $(NAME) $(MLX_LIB)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus : libft $(BONUS)

$(BONUS) : $(OBJ_BONUS) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ_BONUS) $(LIB) -o $(BONUS) $(MLX_LIB)

clean	:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@MAKE -C ./ft_libft/ clean

fclean	:	clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@MAKE -C ./ft_libft/ fclean

re	:	fclean all
