#include <unistd.h>

int input_parse(char *s, int *clues);

int	solve(int grid[4][4], int *clues, int pos);

void print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];
	int	i;

	i = 0;
	while (i < 16)
	{
		grid[i / 4][i % 4] = 0;
		i++;
	}
	if (argc != 2 || !input_parse(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve(grid, clues, 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_grid(grid);
	return (0);
}