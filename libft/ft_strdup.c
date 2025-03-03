/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:01:38 by seerel            #+#    #+#             */
/*   Updated: 2024/10/19 11:58:39 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*src;
	int		i;

	src = (char *)(malloc)(ft_strlen(s1) + 1);
	if (!src)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
