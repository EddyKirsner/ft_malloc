/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:52:05 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:52:07 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	checkneg(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static long	count_number(long n, long neg)
{
	long	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{	
		n = n / 10;
		i++;
	}
	if (neg == 1)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	count;
	long	neg;
	char	*str;

	nb = (long)n;
	neg = checkneg(n);
	if (neg == 1)
		nb = -nb;
	count = count_number(nb, neg);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	while (count > 0)
	{
		str[count - 1] = (nb % 10 + 48);
		nb = nb / 10;
		count--;
	}
	if (neg == 1)
		str[count] = '-';
	return (str);
}
