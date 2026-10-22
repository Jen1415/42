unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	length;

	length = 0;
	while (src[length] && length + 1 < size)
	{
		dest[length] = src[length];
		length++;
	}
	if (size > 0)
		dest[length] = '\0';
	while (src[length])
		length++;
	return (length);
}

#include <stdio.h>
int	main(void)
{
	char	src1[] = "Hello";
	char	src2[] = "Hi";
	char	dest[3];
    int     size = 2;
    int     i = 0;
    ft_strlcpy(dest, src1, size);
    while (dest[i])
    {
        if (dest[i] == '\0')
            printf("\\0");
        else
            printf("%c", dest[i]);
        i++;
    }
    return (0);
}