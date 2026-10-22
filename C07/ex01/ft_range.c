#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*arr = ft_range(0, 1000);
	int	i = 0;
	while (i < 1000)
		printf("%d ", arr[i++]);
	printf("\n");
	free(arr);
	return (0);
}
*/