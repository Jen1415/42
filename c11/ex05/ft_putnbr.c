#include "ex05.h"

void recursion(long long nbr)
{
	char ch;

	if (nbr >= 10)
		recursion(nbr / 10);
	ch = (nbr % 10) + '0';
	write(1, &ch, 1);
}

void ft_putnbr(int nbr)
{
	long long n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	recursion(n);
	write(1, "\n", 1);
}