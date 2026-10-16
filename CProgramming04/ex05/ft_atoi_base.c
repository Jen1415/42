int	check_base(char *base)
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

int	ft_check_nums(char *str, int baselen, char *base)
{
	int	i;
	int	sign;
	int	num;
	int	idx;

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

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;

	baselen = 0;
	if (!check_base(base))
		return (0);
	while (base[baselen])
		baselen++;
	return (ft_check_nums(str, baselen, base));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi_base("\t\n\f\r\v   -++-+--42abc52", "0123456789"));
	printf("%d\n", ft_atoi_base("abc52", "0123456789"));
	return (0);
}
*/