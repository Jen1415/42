/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:34:07 by qjen              #+#    #+#             */
/*   Updated: 2026/10/13 15:04:07 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	ch1;
	unsigned char	ch2;

	i = 0;
	while (s1[i] || s2[i])
	{
		ch1 = s1[i];
		ch2 = s2[i];
		if (ch1 != ch2)
			return (ch1 - ch2);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "hello";
	char *s2 = "hello";

	printf("%d", ft_strcmp(s1, s2));
	return (0);
}
*/
