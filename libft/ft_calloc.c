/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:50:32 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:50:35 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*allocmem;

	allocmem = 0;
	i = nmemb * size;
	if (size && i / size != nmemb)
		return (NULL);
	allocmem = malloc(i);
	if (!allocmem)
		return (NULL);
	ft_bzero(allocmem, i);
	return ((void *)allocmem);
}

/*int	main(void)
{
	char str[10];

    ft_memset(str, 'A', sizeof(str));

    int i;
	
	i = 0; 
	while (i < sizeof(str))
	{
		i++;
		printf("%c ", str[i]);
	}
	return (0);
}*/
