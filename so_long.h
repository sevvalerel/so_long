#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>
#include "minilibx-linux/mlx.h"
typedef struct s_game
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

} t_game;

void	read_map(char *folder, t_game *game)
int error(char *message, t_game *game, int free_check);
int load_map(char *map_file, t_game *game);
int initialize_mlx(t_game *game);
void game_loop(t_game *game);
void cleanup_game(t_game *game);
int key_hook(int keycode, t_game *game);
char	**clonemap(t_game *game);
void	free_map(t_game *game);
void	free_clone(char **map_clone, int map_y);
int map_check(t_game *game);

#endif
