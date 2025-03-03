#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


#include "minilibx-linux/mlx.h"
typedef struct s_game
{
    void    *mlx;
    void    *window;
    char    **map;
    int     player_x;
    int     player_y;
    int     collectible_count;
    int     collected;
}   t_game;

int     load_map(char *map_file, t_game *game);
int     initialize_mlx(t_game *game);
void    game_loop(t_game *game);
void    cleanup_game(t_game *game);
int     key_hook(int keycode, t_game *game);

#endif
