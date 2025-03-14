/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:02:36 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:57:26 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_wall(t_game *game)
{
	int		i;
	char	**map;

	map = game->map;
	i = 0;
	if (game->error != 0)
		error("unknown object", game, 1);
	while (i < game->map_x && map[0][i] != '\n' && map[game->map_y - 2][i] != '\n')
	{
		if (map[game->map_y - 1][i] == '1' && map[0][i] == '1'
			&& (ft_strlen(map[0]) - 1) == game->map_x
			&& game->map_x == ft_strlen(game->map[game->map_y - 1]))
			i++;
		else
			error("The map is not walled or rectangular!", game, 1);
	}
	i = 1;
	while (i < game->map_y - 1)
	{
		if (map[i][0] == '1' && map[i][game->map_x - 1] == '1'
			&& (ft_strlen(map[i]) - 1) == game->map_x)
			i++;
		else
			error("The map is not walled or rectangular.", game, 1);
	}
}

void	read_map(char *folder, t_game *game)
{
	int		y;
	int		fd;
	char	*line;
	int		i;

	y = 0;
	fd = open(folder, O_RDONLY);
	if (fd == -1)
		error("error, can't open file", game, 0);
	game->map = malloc(sizeof(char *) * (game->map_y + 1));
	if (!game->map)
		error("malloc error", game, 1);
	while ((line = get_next_line(fd)))
	{
		game->map[y] = ft_strdup(line);
		i = -1;
		while (line[++i] != '\0')
			handle_element(line[i], game, y, i);
		free(line);
		y++;
	}
	game->map[y] = NULL;
	clonemap(game);
	close(fd);
}

void	line_map(char *folder, t_game *game)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(folder, O_RDONLY);
	if (fd == -1)
		error("error, can't open file", game, 0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	game->map_y = y;
	if (game->map_y == 0)
		error("Map file is empty", game, 0);
}

int	flood_a(int x, int y, char **map, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map_x || y >= game->map_y
		|| map[y][x] == '\0' || map[y][x] == '1' || map[y][x] == 'S'
		|| map[y][x] == '\n')
		return (0);
	if (map[y][x] == 'C')
		game->coin--;
	if (map[y][x] == 'E')
	{
		game->exit_reachable = 1;
		return (1);
	}
	map[y][x] = 'S';
	flood_a(x + 1, y, map, game);
	flood_a(x - 1, y, map, game);
	flood_a(x, y + 1, map, game);
	flood_a(x, y - 1, map, game);
	return (game->exit_reachable);
}
