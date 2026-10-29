#include "ft_map.h"

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};
	int *arr = ft_map(tab, 5, ft_double);
	for (int i = 0; i < 5; i++)
		ft_putnbr(arr[i]);
	return (0);
}