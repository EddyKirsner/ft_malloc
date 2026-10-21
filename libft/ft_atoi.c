/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:50:02 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:50:05 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		nbr;
	int		pos;
	size_t	i;

	nbr = 0;
	pos = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
	i++;
	if (str[i] == '+')
	i++;
	else if (str[i] == '-')
	{
	pos *= -1;
	i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
	nbr = nbr * 10 + str[i] - '0';
	i++;
	}
	return (nbr * pos);
}
