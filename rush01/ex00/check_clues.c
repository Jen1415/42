int	count_visible(int *line, int dir);

void check_cols(int grid[4][4], int i, int *line)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		line[j] = grid[j][i];
		j++;
	}
}

int	check_clues(int grid[4][4], int *clues)
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		check_cols(grid, i, line);
		if (count_visible(grid[i], 1) != clues[i + 8]
			|| count_visible(grid[i], -1) != clues[i + 12]
			|| count_visible(line, 1) != clues[i + 0]
			|| count_visible(line, -1) != clues[i + 4])
			return (0);
		i++;
	}
	return (1);
}