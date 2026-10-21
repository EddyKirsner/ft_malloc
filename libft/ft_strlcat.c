/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:58:20 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:22 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (src == NULL || dst == NULL)
		return (0);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (dstlen + i < dstsize -1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/*
int main()
{
	char a[20] = "bonjour";
	char *b = "akim";
	ft_strlcat(a, b, 15);
	printf("%s", a);
	return (0);
}
*/