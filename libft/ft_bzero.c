/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:50:16 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:50:20 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
			((char *)s)[i] = '\0';
			i++;
	}
}
/*
int main ()
{
	char a[7];
	ft_bzero(a, sizeof(a));
	printf("%s", a);		
}
*/