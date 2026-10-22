#include <unistd.h>

void	print_grid(int grid[4][4])
{
	int		i;
	char	ch;

	i = 0;
	while (i < 16)
	{
		ch = grid[i / 4][i % 4] + '0';
		write(1, &ch, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}