/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:20:34 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:52:37 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->player != NULL && game->coin_c != NULL)
	{
		mlx_destroy_image(game->mlx, game->coin_c);
		game->coin_c = NULL;
		mlx_destroy_image(game->mlx, game->player);
		game->player = NULL;
	}
	if (game->exit_m != NULL && game->wall != NULL)
	{
		mlx_destroy_image(game->mlx, game->exit_m);
		game->exit_m = NULL;
		mlx_destroy_image(game->mlx, game->wall);
		game->wall = NULL;
	}
	if (game->floor != NULL)
	{
		mlx_destroy_image(game->mlx, game->floor);
		game->floor = NULL;
	}
}
