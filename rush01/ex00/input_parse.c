int input_parse(char *s, int *clues)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (s[i] < '1' || s[i] > '4' || count == 16)
				return (0);
			clues[count++] = s[i] - '0';
		}
		else if (s[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16 && i == 31);
}