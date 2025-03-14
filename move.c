/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:30:03 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:58:17 by seerel           ###   ########.fr       */
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

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == 'C')
		game->coin--;
	else if (game->map[game->player_y - 1][game->player_x] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			win(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->move += 1;
		game->player_y--;
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == 'C')
		game->coin--;
	else if (game->map[game->player_y + 1][game->player_x] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			win(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->move += 1;
		game->player_y++;
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == 'C')
		game->coin--;
	else if (game->map[game->player_y][game->player_x - 1] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			win(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->player_x--;
		game->move += 1;
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == 'C')
		game->coin--;
	else if (game->map[game->player_y][game->player_x + 1] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			win(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->player_x++;
		game->move += 1;
	}
}

int	key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_up(game);
	else if (keycode == 97 || keycode == 65361)
		move_left(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
	else
		return (0);
	ft_printf("Move: %d Coin: %d\n", game->move, game->coin);
	return (0);
}
