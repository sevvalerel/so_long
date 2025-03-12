/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:05:22 by seerel            #+#    #+#             */
/*   Updated: 2024/10/22 21:24:02 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_step(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_step(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[len - 1] = '0';
	while (len > 0)
	{
		if (n == 0 && len == 1)
			break ;
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
