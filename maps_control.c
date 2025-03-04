#include "so_long.h"

int map_check(t_game *game)
{
    if(game->coin<1)
        error("ERROR!,No Coin",game,1);
    if(game->player_c !=1)
        error("ERROR!,Numbers of players is not 1",game,1);
    if (game->exit != 1)
		error("ERROR!,No Exit", game, 1);
    
    
}
  