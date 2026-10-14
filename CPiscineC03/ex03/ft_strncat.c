/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:40:02 by qjen              #+#    #+#             */
/*   Updated: 2026/10/13 15:58:35 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int main() {

    char dest[8] = "hi";
    ft_strncat(dest, "world", 3);
    for (int i = 0; i < 6; i++)
        {
            if (dest[i] == '\0')
                printf("\\0");
            else
                printf("%c", dest[i]);
        }
    return 0;
}
*/
