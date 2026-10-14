/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:51:06 by qjen              #+#    #+#             */
/*   Updated: 2026/10/14 16:51:08 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	destcnt;
	unsigned int	srccnt;

	destlen = 0;
	srccnt = 0;
	while (destlen < size && dest[destlen])
		destlen++;
	destcnt = destlen;
	while (src[srccnt] && size > destcnt + 1)
		dest[destcnt++] = src[srccnt++];
	while (src[srccnt])
		srccnt++;
	if (size > destlen)
	{
		dest[destcnt] = '\0';
		return (destlen + srccnt);
	}
	else
		return (size + srccnt);
}

/*
#include <stdio.h>
int main(void)
{
    char dest[] = {'a','b','d','e'};
    char src[] = "";
    unsigned int size = 4;

    printf("size: %d\n", ft_strlcat(dest, src, size));
	printf("dest: %s\n", dest);
}
*/