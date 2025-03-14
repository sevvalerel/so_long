/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:54 by seerel            #+#    #+#             */
/*   Updated: 2025/03/14 10:47:31 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_element(char object, t_game *game, int first_y, int first_x)
{
	if (object == 'P')
	{
		game->player_c++;
		game->player_x = first_x;
		game->player_y = first_y;
	}
	else if (object == 'C')
		game->coin++;
	else if (object == 'E')
		game->exit++;
	else if (object != '0' && object != '1' && object != '\n' && object != '\0')
		game->error++;
}

void	clonemap(t_game *game)
{
	int	i;

	i = 0;
	game->map_clone = malloc(sizeof(char *) * (game->map_y + 1));
	if (!game->map_clone)
		error("malloc error", game, 1);
	while (i < game->map_y)
	{
		game->map_clone[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map_clone[i] = NULL;
}

char	**fullmap_import(char *folder, char **fullmap, t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	int		p_y;

	p_y = 0;
	fd = open(folder, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fullmap[p_y] = ft_strdup(line);
		i = 0;
		while (line[i] != '\0')
		{
			handle_element(line[i], game, p_y, i);
			i++;
		}
		free(line);
		p_y++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (fullmap);
}

void	map(char *folder, t_game *game)
{
	int	folder_check;

	folder_check = ft_strlen(folder);
	game->error = 0;
	game->exit = 0;
	game->coin = 0;
	game->move = 0;
	if (folder[folder_check - 4] == '.' && folder[folder_check - 3] == 'b'
		&& folder[folder_check - 2] == 'e' && folder[folder_check - 1] == 'r')
	{
		line_map(folder, game);
		read_map(folder, game);
	}
	else
		error("file extension is wrong", game, 0);
	if (game->map[0] == NULL)
		error("map import error", game, 0);
	game->map_x = ft_strlen(game->map[0]) - 1;
}
