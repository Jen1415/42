/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:36:25 by qjen              #+#    #+#             */
/*   Updated: 2026/10/25 17:36:29 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

void	nbr_to_str(char *str, long long num, char *base_to, int baselen)
{
	while (num >= baselen)
		nbr_to_str(str, num / baselen, base_to, baselen);
	str = base_to[num % baselen];
}

void	malloc_str(char *str, long long num, char *base_to)
{
	int	baselen;
	int	bytes;
	int	index;
	int	negative;

	baselen = 0;
	bytes = 1;
	index = 0;
	negative = 0;
	while (base_to[baselen])
		baselen++;
	if (num < 0)
	{
		bytes++;
		num = -num;
		negative = 1;
	}
	while (num >= baselen)
	{
		num /= baselen;
		bytes++;
	}
	str = malloc(bytes + 1);
	if (negative)
		str[index++] = '-';
	nbr_to_str(str, num, base_to, baselen);
	str[bytes] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	long long	num;

	if (!(is_valid_base(base_from) && is_valid_base(base_to)))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	if (num < -2147483648 || num > 2147483647)
		return (NULL);
	malloc_str(str, num, base_to);
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_convert_base("123", "0123456789", "01"));
	return (0);
}
