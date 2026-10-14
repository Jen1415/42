/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:58:02 by qjen              #+#    #+#             */
/*   Updated: 2026/10/13 15:58:03 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	if (!tofind[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = i;
		k = 0;
		while (str[j] && str[j] == to_find[k])
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "";
	char *to_find = "";
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
*/