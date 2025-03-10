/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:54 by seerel            #+#    #+#             */
/*   Updated: 2025/03/10 20:44:23 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	**clonemap(t_game *game)
{
	int		i;
	char	**clone;

	i = 0;
	clone = malloc(sizeof(char *) * (game->map_y + 1));
	if (!clone)
		error("malloc error", game, 1);
	while (i < game->map_y)
	{
		clone[i] = ft_strdup(game->map[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (i < game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
void	free_clone(char **map_clone, int map_y)
{
	int	i;

	if (!map_clone)
		return ;
	i = 0;
	while (i < map_y)
	{
		if (map_clone[i])
			free(map_clone[i]);
		i++;
	}
	free(map_clone);
}