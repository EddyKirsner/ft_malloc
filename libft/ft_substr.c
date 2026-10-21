/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:59:45 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:59:47 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*str;

	i = 0;
	len_s = ft_strlen((char *)s);
	if (start >= len_s)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
		len = len_s - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char const	*str ="bonjour les amis";
	char *str2;
	unsigned int i = 2;
	size_t len =7;
	str2 = ft_substr(str, i, len);
	return (0);
}
*/