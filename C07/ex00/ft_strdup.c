#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	
	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char *src = "hello world";
	char *dest = ft_strdup(src);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
*/