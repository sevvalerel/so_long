/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:56 by seerel            #+#    #+#             */
/*   Updated: 2025/03/16 20:38:01 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_game *game)
{
	ft_printf("🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉\n");
	ft_printf("                                               \n");
	ft_printf("               🎊 You are WİN 🎊               \n");
	ft_printf("🔥 Just in time! You got here before the tea got cold!\n");
	ft_printf("                                               \n");
	ft_printf("🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉\n");
	close_game(game);
}

int	map_check(t_game *game)
{
	int	coin;

	coin = game->coin;
	game->exit_reachable = 0;
	if (game->coin < 1)
		error("No Coin", game, 1);
	if (game->player_c != 1)
		error("Numbers of players is not 1", game, 1);
	if (game->exit != 1)
		error("Numbers of Exit is not 1", game, 1);
	check_wall(game);
	if (flood_a(game->player_x, game->player_y, game->map_clone, game) == 0
		|| game->exit_reachable == 0)
	{
		return (error("Exit or coin path is closed", game, 1));
	}
	if (game->coin > 0)
		return (error("Not all coins are collectible", game, 1));
	free_map_clone(game);
	game->coin = coin;
	return (0);
}

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
	game.win = mlx_new_window(game.mlx,
			(game.map_x * 64), (game.map_y * 64), "So Long");
	if (!game.win)
		error("Failed to create window", &game, 1);
	images(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
