/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:35:03 by buket             #+#    #+#             */
/*   Updated: 2024/11/25 14:17:11 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *x)
{
	size_t	i;

	i = 0;
	while (x[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i] != '\0')
		str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (str);
}

int	new_check(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
