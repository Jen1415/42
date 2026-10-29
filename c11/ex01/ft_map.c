#include <stdlib.h>
#include "ft_map.h"

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i = 0;
	int *arr = malloc(sizeof(int) * length);

	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}