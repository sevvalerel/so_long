/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:01 by seerel            #+#    #+#             */
/*   Updated: 2024/10/19 11:57:53 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
	{
		ft_memcpy(d, s, len);
	}
	else
	{
		d = d + (len);
		s = s + (len);
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	return (dst);
}
