/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:12:53 by seerel            #+#    #+#             */
/*   Updated: 2024/10/19 19:09:49 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;
	char	x;

	x = (char)c;
	p = (char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == x)
			return (p + i);
		i++;
	}
	return (NULL);
}
