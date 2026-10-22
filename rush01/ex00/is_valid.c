int	is_valid(int grid[4][4], int pos, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[pos / 4][i] == val || grid[i][pos % 4] == val)
			return (0);
		i++;
	}
	return (1);
}