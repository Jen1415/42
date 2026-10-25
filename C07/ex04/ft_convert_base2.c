/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:36:35 by qjen              #+#    #+#             */
/*   Updated: 2026/10/25 17:36:37 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_index(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_check_nums(char *str, int baselen, char *base)
{
	int			i;
	int			sign;
	long long	num;
	int			idx;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	idx = ft_base_index(str[i], base);
	while (idx != -1)
	{
		num = num * baselen + idx;
		i++;
		idx = ft_base_index(str[i], base);
	}
	return (sign * num);
}

long long	ft_atoi_base(char *str, char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	return (ft_check_nums(str, baselen, base));
}
