/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:54:23 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:54:24 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (n-- > 0)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	return (dest);
}

/*int main(void)
{
	char	src[50] = "akim";
	char	dst[50];
	char	*ret;
	
	ret = ft_memmove(dst, src, 10);
	printf("%s\n", ret);
	return 0;	
}*/