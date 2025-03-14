/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:56 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:56:25 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	free_images(game);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	free_map_clone(game);
	exit(0);
}

int	game_loop(t_game *game)
{
	map_import_window(game, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc == 2)
		map(argv[1], &game);
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
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
