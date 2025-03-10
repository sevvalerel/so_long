/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:56 by seerel            #+#    #+#             */
/*   Updated: 2025/03/10 21:38:06 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc,char **argv)
{
    t_game game;
    
    ft_memset(&game,0,sizeof(t_game));
    if(argc==2)
        map(argv[1],&game);
    else
        error("Wrong argument, please select map.", &game, 0);
    map_check(&game);
    game.mlx=mlx_init();
    	error("Failed to initialize MinilibX.\n", &game, 1);
    game.win = mlx_new_window(game.mlx, (game.map_x * 64), (game.map_y * 64),"So Long");
    if (game.win == NULL)
        error("failed to create window", &game, 1);
}