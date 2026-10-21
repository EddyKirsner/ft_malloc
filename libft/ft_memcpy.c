/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:54:12 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:54:14 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;
	
	if (src == NULL || dest == NULL)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == 0 && src == 0)
		return (NULL);
	d = dst;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

/*
int main()
{
	char a[30] = "bonjour";
	char b[30];
	ft_memcpy(b,a,8);
	printf("%s", b);
	return (0);
}
*/
