/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:44 by seerel            #+#    #+#             */
/*   Updated: 2025/03/04 20:26:41 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error(char *message, t_game *game, int free_check)
{
    ft_printf("Error: %s\n", message);
    if (free_check && game)
    {
        if (game->map)
            free_map(game);
        if (game->map_clone)
            free_clone_map(game->map_clone,game->map_y);
    }
    exit(EXIT_FAILURE);
    
}

void free_map(t_game *game)
{
    int i;

    if (!game || !game->map)
        return;
    i = 0;
    while (i < game->map_y) // y ler satır olduğu için
    {
        free(game->map_y);
        i++;
    }
    free(game->map);
    game->map = NULL;
}

void free_clone_map(char **map_clone,int map_y)
{
    int i;

    if (!map_clone)
        return ;
    i = 0;
    while (i < map_y)
    {
        if(map_clone[i])
            free(map_clone[i]);
        i++;
    }
    free(map_clone);

}