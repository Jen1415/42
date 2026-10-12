#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;
	unsigned char	c;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		c = str[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		i++;
	}
}

int	main(void)
{
	char str[] = "\x80\xff";
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}