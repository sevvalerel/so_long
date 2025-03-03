/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:07:17 by seerel            #+#    #+#             */
/*   Updated: 2024/10/20 15:12:29 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*src;

	src = malloc(count * size);
	if (!src)
		return (NULL);
	else
	{
		ft_bzero(src, count * size);
		return (src);
	}
}
