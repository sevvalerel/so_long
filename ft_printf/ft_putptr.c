/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:27:01 by seerel            #+#    #+#             */
/*   Updated: 2024/11/03 18:52:16 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpptr(void *ptr)
{
	int				counter;
	unsigned long	n;
	char			*hex;

	counter = 0;
	n = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		counter += ft_putpptr((void *)(n / 16));
	}
	counter += write(1, &hex[n % 16], 1);
	return (counter);
}

int	ft_putptr(unsigned long n, char *hex)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_putptr(n / 16, hex);
		counter += ft_putchar(hex[n % 16]);
	}
	else
		counter += ft_putchar(hex[n % 16]);
	return (counter);
}
