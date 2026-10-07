#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	i;
	unsigned int	n;
	char	buffer[10];
	
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	
	n = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -n;
	}

	while (n > 0)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
	}
}

int	main(void)
{
	ft_putnbr(-42);
	return (0);
}