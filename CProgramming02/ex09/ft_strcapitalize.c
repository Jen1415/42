#include <unistd.h>

void	ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')))
			{
				flag = 1;
				write(1, &str[i], 1);
			}
		else
		{
			if ((str[i] >= 'a' && str[i] <= 'z') && flag)
				write(1, &(str[i] - 32), 1);
			else if (!flag && (str[i] >= 'A' && str[i] <= 'Z'))
				write(1, &(str[i] + 32), 1);
			flag = 0;
		}
		i++;
	}
}


int	main(void)
{
	char str[] = "HELLO";
	ft_strcapitalize(str);
	return 0;
}