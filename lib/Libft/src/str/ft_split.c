/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:17 by nseon             #+#    #+#             */
/*   Updated: 2024/11/19 10:24:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
	return (0);
}

static int	set_l(int *l)
{
	*l = -1;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	k = 0;
	tab = ft_calloc(count_w(s, c) + 1, sizeof (char *));
	if (tab == NULL)
		return (ft_free(tab));
	while (++i < count_w(s, c) && set_l(&l))
	{
		while (s[k] && s[k] == c)
			k++;
		j = k;
		while (s[k] && s[k] != c)
			k++;
		tab[i] = ft_calloc((k - j) + 1, sizeof (char));
		if (tab[i] == NULL)
			return (ft_free(tab));
		while (j < k)
			tab[i][++l] = s[j++];
	}
	return (tab);
}
