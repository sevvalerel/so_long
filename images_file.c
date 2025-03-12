/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:28:47 by seerel            #+#    #+#             */
/*   Updated: 2025/03/12 14:28:51 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void images(t_game *game)
{
    int w;
    int h;

    game->player =mlx_xpm_file_to_image(game->mlx,"images/player.xpm",&w,&h);
    if(game->player==NULL)
        error("error!,player xpm",game,1);
    game->coin_c=mlx_xpm_file_to_image(game->mlx,"images/coin.xpm",&w,&h);
    if(game->coin_c==NULL)
        error("error!,coin xpm",game,1);
    game->floor=mlx_xpm_file_to_image(game->mlx,"images/floor.xpm",&w,&h);
    if(game->floor==NULL)
        error("error!,floor xpm",game,1);
    game->exit_m = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
	if (game->exit_m == NULL)
		error("xpm error exit", game, 1);
	game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
	if (game->wall == NULL)
		error("xpm error wall", game, 1);
}

void	map_import_window(t_game *game, int x, int y)
{
	while (y < game->map_y)
	{
		while (x < game->map_x)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x
					* 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, x
					* 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coin_c, x
					* 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_m, x
					* 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, x
					* 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
}