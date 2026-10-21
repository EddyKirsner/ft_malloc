/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:56:30 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:56:33 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	superc;

	superc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == superc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == superc)
		return ((char *) &s[i]);
	return (NULL);
}
/*
int main()
{
	char *a = "bonjour";
	int b = 106; // pour tester a partir du j
	printf("%s", ft_strchr(a,b));
	return (0);
}
*/