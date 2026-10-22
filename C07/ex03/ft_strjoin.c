/*
• Write a function that concatenates all the strings pointed to by strs, separated by sep.
• size is the number of strings in strs.
• If size is 0, you must return an empty string that can be freed using free().
*/

#include <stdlib.h>

int	ft_strslen(int size, char **strs)
{
	int	i;
	int	strssize;
	int	strcount;

	strssize = 0;
	strcount = 0;
	while (strssize < size)
	{
		i = 0;
		while (strs[strssize][i])
		{
			i++;
			strcount++;
		}
		strssize++;
	}
	return (strcount);
}

int	ft_seplen(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	ft_strscat(int size, char *str, char **strs, char *sep)
{
	int	i;
	int	strssize;
	int	stri;

	i = 0;
	strssize = 0;
	stri = 0;
	while (strssize < size)
	{
		i = 0;
		while (strs[strssize][i])
			str[stri++] = strs[strssize][i++];
		strssize++; 
		if (strssize < size)
		{
			i = 0;
			while (sep[i])
				str[stri++] = sep[i++];
		}
	}
	return (stri);
}

char	*ft_empty_str(void)
{
	char	*str;
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	strcount;
	int	sepcount;
	int	stri;
	char *str;

	if (size == 0)
		return (ft_empty_str());
	strcount = ft_strslen(size, strs);
	sepcount = ft_seplen(sep);
	str = malloc((strcount + 1) + (size - 1) * sepcount);
	if (!str)
		return (NULL);
	stri = ft_strscat(size, str, strs, sep);
	str[stri] = '\0';
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char *a[] = {"hello", "world", "42"};
	char *s;
	s = ft_strjoin(3, a, ", ");
	printf("%s\n", s);   // hello, world, 42
	free(s);
	s = ft_strjoin(1, a, ", ");
	printf("%s\n", s);   // hello
	free(s);
	s = ft_strjoin(0, a, ", ");
	printf("[%s]\n", s);   // []
	free(s);
	s = ft_strjoin(2, a, "");
	printf("%s\n", s);   // helloworld
	free(s);
	return (0);
}