/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:10:08 by qjen              #+#    #+#             */
/*   Updated: 2026/10/07 18:25:53 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	buffer[12];
	int	i;
	unsigned int	n;

	i = 0;
	n = nb;

	if (n	b == 0)
	{
		write(1, "0", 1);
		return;
	}

	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
	}
}

int	main()
{
	ft_putnbr(42);
	return (0);
}
