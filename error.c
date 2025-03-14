/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:44 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:51:54 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_map_clone(t_game *game)
{
	int	i;

	if (!game->map_clone)
		return ;
	i = 0;
	while (i < game->map_y)
	{
		if (game->map_clone[i])
		{
			free(game->map_clone[i]);
			game->map_clone[i] = NULL;
		}
		i++;
	}
	free(game->map_clone);
	game->map_clone = NULL;
}

int	error(char *message, t_game *game, int free_check)
{
	ft_printf("Error: %s\n", message);
	if (free_check && game)
	{
		if (game->map)
			free_map(game);
		if (game->map_clone)
			free_map_clone(game);
	}
	free_images(game);
	exit(EXIT_FAILURE);
}
