/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:58:39 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:41 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

/*
int main ()
{   
				char *a = "bonjour";
				printf ("%d",ft_strlen(a));
				return (0);
}
*/
