/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:28:24 by seerel            #+#    #+#             */
/*   Updated: 2024/10/19 18:25:50 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (*(s + len) != (char)c && len > 0)
		len--;
	if (*(s + len) == (char)c)
		return ((char *)(s + len));
	else
		return (NULL);
}
