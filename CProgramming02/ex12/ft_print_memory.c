/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:26:45 by qjen              #+#    #+#             */
/*   Updated: 2026/10/11 19:26:47 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	addrl;
	int		i;
	int		count;
	char	*hex;
	unsigned char	*bytes;

	count = 0;
	hex = "0123456789abcdef";
	bytes = (unsigned char *)addr;


	while (count < size && size > 0)
	{
		// write the address down
		i = 15;
		addrl = (unsigned long)(bytes + count);
		while (i >= 0)
		{
			write(1, &hex[(addrl >> (i * 4)) & 0xf], 1);
			i--;
		}
		write(1, ":", 1);

		// reset counter and write 16 bytes
		i = count;
		while (i < count + 16  && i < size)
		{
			if (i % 2 == 0)
				write(1, " ", 1);
			write(1, &hex[bytes[i] / 16], 1);
			write(1, &hex[bytes[i] % 16], 1);
			i++;
		}
		while (i < count + 16)
		{
			if (i % 2 == 0)
				write(1, " ", 1);
			write(1, "  ", 2);
			i++;
		}
		write(1, " ", 1);


		// reset counter and write 16 characters
		i = count;
		while (i < count + 16 && i < size)
		{
			if (!(bytes[i] >= 32 && bytes[i] <= 126))
				write(1, ".", 1);
			else
				write(1, &bytes[i], 1);
			i++;
		}


		// go to a new line
		count += 16;
		write(1, "\n", 1);
	}
	return (addr);
}


int	main(void)
{
	char	str[] = "Hello\n\t\x01\x7f\x80\xff";
	ft_print_memory(str, sizeof(str));
	return (0);
}
