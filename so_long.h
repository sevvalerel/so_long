#ifndef SO_LONG_H
#define SO_LONG_H



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct game
{
    void *mlx;
    void *win;
    void *floor_img;
    void *coin_img;
    void *character_img;
    char **map;
    int map_width;
    int map_height;
    int player_x;
    int player_y;
    int player_c;
    int map_x;
    int map_y;
    char **map_clone;
    int coin;
    int exit;
    int error;
    void *player;
    void *wall;
    void *coin_c;
    void *floor;
    void *exit_m;
    int move;
    int exit_y;
    int exit_x;

}   t_game;

void	read_map(char *folder, t_game *game);
int error(char *message, t_game *game, int free_check);
int load_map(char *map_file, t_game *game);
int initialize_mlx(t_game *game);
int game_loop(t_game *game);
void cleanup_game(t_game *game);
int key_hook(int keycode, t_game *game);
void	clonemap(t_game *game);
void	free_map(t_game *game);
void	free_clone(char **map_clone, int map_y);
int map_check(t_game *game);
void	map_import_window(t_game *game, int x, int y);
void images(t_game *game);
void free_map_clone(t_game *game);
int flood_a(int x, int y, char **map, t_game *game);
void	map(char *folder, t_game *game);
void line_map(char *folder, t_game *game);


#endif
