#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_recurs(unsigned int nbr, char *base, unsigned int baselen)
{
	if (nbr >= baselen)
		ft_recurs(nbr / baselen, base, baselen);	
	write(1, &base[nbr % baselen], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int n;
	unsigned int baselen;

	baselen = 0;
	if (check_base(base))
	{
		n = nbr;
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		while (base[baselen])
			baselen++;
		ft_recurs(n, base, baselen);
	}
}

#include <limits.h>
int	main(void)
{
	ft_putnbr_base(5, "");
	ft_putnbr_base(5, "1");
	ft_putnbr_base(5, "11");
	ft_putnbr_base(5, "+0123");
	ft_putnbr_base(5, "-0123");
	ft_putnbr_base(INT_MIN, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(INT_MAX, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(255, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(8, "01");
	write(1, "\n", 1);
	return (0);
}