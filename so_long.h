#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "./ft_libft/libft.h"
//#include "./ft_get_next_line/get_next_line.h"
#include "./minilibx_macos/mlx.h"

# define TILE_X 64
# define TILE_Y 64
# define WALL "game_assets/wall.xpm"
# define FLOOR "game_assets/back.xpm"
# define PLAYER "game_assets/player1.xpm"
# define EXIT1 "game_assets/exit.xpm"
# define COL1 "game_assets/blue_crystal_0000.xpm"
//# define COL2 "game_assets/blue_crystal_0001.png"

typedef struct s_pl
{
	int		x;
	int 	y;
} t_pl;

typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*col1;
	void	*col2;
	void	*exit;
} t_image;

typedef struct s_map
{
	char	**map;
	char	*contents;
	int		fd;
	int 	length;
	int 	height;
	void	*mlx;
	void	*window;
	int 	col_num;
	int 	steps;
	void	*image1;
	t_pl	player_pos;
	t_image	img;
} t_map;

void	ft_error(char *str);
char	*ft_get_line(t_map *map);
void	ft_check_arg(char *str, t_map *map);
t_map	*ft_init_map(t_map *map);
void	ft_check_map(t_map *map);
void	ft_check_len(t_map *map);
void	ft_check_walls(t_map *map);
void	ft_check_pce(t_map *map, int p, int c, int e);
void	ft_check_symbols(t_map *map, char *str);
void	ft_push_sprites(t_map *map);
void	ft_print_map(t_map *map);
void	ft_push_image(t_map *map, int i, int j);
void	ft_push_player(t_map *map);
void	ft_moves(t_map *map);

/* GNL_BAKYT */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, char *str);

#endif
