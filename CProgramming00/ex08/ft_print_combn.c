#include <unistd.h>

void	print_comb(char *comb, int n)
{
	write(1, comb, n);
	if (comb[0] != '9' - n + 1)
		write(1, ", ", 2);
}

void	build(char *comb, int n, int pos, char start)
{
	if (pos == n)
	{
		print_comb(comb, n);
		return ;
	}
	while (start <= '9')
	{
		comb[pos] = start;
		build(comb, n, pos + 1, start + 1);
		start++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	build(comb, n, 0, '0');
}

int	main(void)
{
	ft_print_combn(2);
	return (0);
}