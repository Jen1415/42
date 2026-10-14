/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:11:33 by qjen              #+#    #+#             */
/*   Updated: 2026/10/13 15:30:57 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main() {

    char dest[7] = "hel";
    char src[] = "str";
    ft_strcat(dest, src);
    for (int i = 0; i < 7; i++)
        {
		if (dest[i] == '\0')
			printf("\\0");
		else
            		printf("%c", dest[i]);
        }
    return 0;
}
*/
