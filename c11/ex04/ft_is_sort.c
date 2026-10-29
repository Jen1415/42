int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i = 1;
	int	asc = 1;
	int desc = 1;

	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			asc = 0;
		if (f(tab[i - 1], tab[i] < 0))
			desc = 0;
		i++;
	}
	return (asc || desc);
}