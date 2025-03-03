/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:27:54 by seerel            #+#    #+#             */
/*   Updated: 2024/11/03 18:50:47 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = 0;
	write(1, &c, 1);
	counter += 1;
	return (counter);
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		counter += ft_putchar(*str);
		str++;
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	ft_putunbr(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putunbr(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}
