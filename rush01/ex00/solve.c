int	check_clues(int grid[4][4], int *clues);

int	is_valid(int grid[4][4], int pos, int val);

int	solve(int grid[4][4], int *clues, int pos)
{
	int	val;

	val = 1;
	if (pos == 16)
		return (check_clues(grid, clues));
	while (val <= 4)
	{
		if (is_valid(grid, pos, val))
		{
			grid[pos / 4][pos % 4] = val;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[pos / 4][pos % 4] = 0;
		}
		val++;
	}
	return (0);
}