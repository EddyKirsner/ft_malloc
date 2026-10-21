/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:55:51 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:55:53 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		nb;
	long	nbr;

	nbr = n;
	if (nbr == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		ft_putnbr_fd(nbr, fd);
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
		else
		{
			nb = nbr + 48;
			write(fd, &nb, 1);
		}
	}
}
/*
int main()
{
	ft_putnbr_fd(5555, 1);
	return (0);
}
*/