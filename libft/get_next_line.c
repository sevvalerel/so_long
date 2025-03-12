/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:10:25 by seerel            #+#    #+#             */
/*   Updated: 2025/03/12 16:47:33 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_read(int fd, char *buffer)
{
	char	*line;
	int		read_byte;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_byte = 1;
	while (!new_check(buffer) && read_byte > 0)
	{
		read_byte = read(fd, line, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line[read_byte] = '\0';
		buffer = ft_strjoin_modified(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*f_swap(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i && buffer[j])
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j++] = buffer[i];
	line[j] = '\0';
	return (line);
}

char	*get_new(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen_modified(buffer) - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = f_read(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = f_swap(buffer);
	buffer = get_new(buffer);
	return (line);
}
