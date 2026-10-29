#include "ft_foreach.h"

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, ft_putnbr);
	return (0);
}