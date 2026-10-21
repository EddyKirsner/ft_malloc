/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:59:07 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:59:09 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

/*int	main(void)
{
	const char	*str1;
	const char	*str2;

	str1 = "1";
	str2 = "5";
	printf("%d\n", ft_strncmp(str1, str2, 6));
	printf("%d\n", ft_strncmp(str1, str2, 0));
	return (0);

}*/
