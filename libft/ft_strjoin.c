/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:57:14 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:57:16 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	flen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc((flen + 1) * (sizeof(const char)));
	if (str == NULL)
		return (NULL);
	while (s1[j])
	{
		str[j] = (char)s1[j];
		j++;
	}
	while (s2[i])
	{
		str[j] = (char)s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
/*
int main()
{
	char *str;
	const char *str2 = "bonjour";
	const char *str3 = "les";
	str = ft_strjoin(str2, str3);
	printf("%s", str);
	return (0);
}
*/