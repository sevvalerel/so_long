/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:08 by seerel            #+#    #+#             */
/*   Updated: 2024/10/19 19:05:37 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstl;

	dstl = ft_strlen(dst);
	j = dstl;
	i = 0;
	if (dstsize <= dstl)
	{
		return (dstsize + ft_strlen(src));
	}
	while (src[i] != '\0' && i < (dstsize - dstl - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dstl + ft_strlen(src));
}
