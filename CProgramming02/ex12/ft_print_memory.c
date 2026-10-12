#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	addrl;
	char	*hex;
	int		i;

	addrl = (unsigned long) addr;
	hex = "0123456789abcdef";
	i = 15;
	printf("%016lx\n", addrl);
	while (i >= 0)
	{
		write(1, &hex[(addrl >> (i * 4)) & 0xf], 1);
		i--;
	}
	return (addr);
}

int	main(void)
{
	int a = 8;
	int *b = &a;
	ft_print_memory(&a, 4);
	write(1, "\n", 1);
	ft_print_memory(b, 4);
	write(1, "\n", 1);
	return (0);
}