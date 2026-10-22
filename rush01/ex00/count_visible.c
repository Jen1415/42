int	count_visible(int *line, int dir)
{
	int	i;
	int	count;
	int	max;
	
	i = 0;
	count = 0;
	max = 0;
	if (dir == -1)
		i = 3;
	while (i >= 0 && i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i += dir;
	}
	return (count);
}