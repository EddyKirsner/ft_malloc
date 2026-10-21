/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:59:18 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:59:19 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (big == 0 && n == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i <= n)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j < n))
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strnstr("grand-papaoups", "papa", 50));
}*/
