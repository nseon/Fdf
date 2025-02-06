/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:58:39 by nseon             #+#    #+#             */
/*   Updated: 2024/11/14 17:34:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb <= 9)
	{
		nb += '0';
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		write (fd, &"0123456789"[nb % 10], 1);
	}
}
