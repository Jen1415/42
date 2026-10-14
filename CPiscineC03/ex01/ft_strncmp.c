/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by qjen              #+#    #+#             */
/*   Updated: 2026/10/13 15:09:15 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	ch1;
	unsigned char	ch2;

	i = 0;
	while (i < n)
	{
		ch1 = s1[i];
		ch2 = s2[i];
		if (ch1 != ch2 || ch1 == '\0')
			return (ch1 - ch2);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main() {

    char *s1 = "A";
    char *s2 = "A";
    printf("%d", ft_strncmp(s1, s2, 5));
    return 0;
}
*/