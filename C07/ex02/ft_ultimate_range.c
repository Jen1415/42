#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * (size));
	if (!(*range))
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (size);
}

#include <stdio.h>
int	main(void)
{
	int *range;
	int size = ft_ultimate_range(&range, 0, 9);
	int i = 0;
	printf("size: %d\n", size);
	while (i < size)
		printf("%d ", (range[i++]));
	printf("\n");
	free(range);
	return (0);
}