cmake_minimum_required(VERSION 3.20)
project(07_so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(07_so_long so_long.c so_long.h src_so_long/ft_error.c src_so_long/ft_utils.c src_so_long/ft_map_func1.c ft_get_next_line/get_next_line_utils.c src_so_long/ft_get_next_line.c src_so_long/ft_check_map.c src_so_long/ft_push_sprites.c src_so_long/ft_moves1.c src_so_long/ft_player_actions.c)

add_custom_target(
        mlx.h
        COMMAND make
        minilibx_macos
)
add_executable(minilibx_macos minilibx_macos/mlx_shaders.c minilibx_macos/mlx_new_window.m minilibx_macos/mlx_init_loop.m minilibx_macos/mlx_new_image.m minilibx_macos/mlx_xpm.c minilibx_macos/mlx_int_str_to_wordtab.c)
target_link_libraries(minilibx_macos)
add_dependencies(minilibx_macos mlx.h)