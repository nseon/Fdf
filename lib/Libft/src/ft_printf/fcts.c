/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:50:54 by nseon             #+#    #+#             */
/*   Updated: 2025/01/14 12:15:36 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	count(unsigned long long int n, int div)
{
	int	count;

	count = 0;
	while (n >= 1)
	{
		count++;
		n /= div;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*uitoa_base(unsigned long long int n, char c
		, char *base, unsigned int div)
{
	int		i;
	char	*tab;

	i = count(n, div);
	if (n == 0 && c == 'p')
		return ("(nil)");
	tab = ft_calloc(count(n, div) + 1, (sizeof (char)));
	if (tab == NULL)
		return (0);
	while (n >= div)
	{
		tab[--i] = base[n % div];
		if (c == 'X' && 'a' <= tab[i] && tab[i] <= 'f')
			tab[i] -= 32;
		n /= div;
	}
	tab[--i] = base[n];
	if (c == 'X' && 'a' <= tab[i] && tab[i] <= 'f')
		tab[i] -= 32;
	return (tab);
}

int	ft_strlen2(const char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (6);
	while (s[n] != '\0')
		n++;
	return (n);
}
