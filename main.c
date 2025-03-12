/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:56 by seerel            #+#    #+#             */
/*   Updated: 2025/03/12 15:53:06 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h> // memset için gerekli

int game_loop(t_game *game)
{
    map_import_window(game, 0, 0);
    return (0);
}

int main(int argc, char **argv)
{
    t_game game;

    ft_memset(&game, 0, sizeof(t_game)); // ft_memset yerine memset kullanıldı

    if (argc == 2)
        map(argv[1], &game); // map() yerine load_map() kullanıldı
    else
        error("Wrong argument, please select map.", &game, 0);

    map_check(&game);

    game.mlx = mlx_init();
    if (!game.mlx)
        error("Failed to initialize MinilibX.\n", &game, 1);

    game.win = mlx_new_window(game.mlx, (game.map_x * 64), (game.map_y * 64), "So Long");
    if (!game.win)
        error("Failed to create window", &game, 1);

    images(&game);

    // Event hooks

   
    mlx_loop_hook(game.mlx, game_loop, &game); // Oyun döngüsü

    mlx_loop(game.mlx); // Sonsuz döngü

    return (0);
}
