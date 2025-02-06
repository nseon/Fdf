/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:10:11 by nseon             #+#    #+#             */
/*   Updated: 2024/11/19 10:20:53 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 1)
	{
		count++;
		n /= 10;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*tab;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = count(n) - 1;
	tab = ft_calloc(count(n) + 1, (sizeof (char)));
	if (tab == NULL)
		return (0);
	if (n < 0)
	{
		n = -n;
		tab[0] = '-';
	}
	while (n > 9)
	{
		tab[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	tab[i] = n + '0';
	return (tab);
}
