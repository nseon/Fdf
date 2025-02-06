/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:22:29 by nseon             #+#    #+#             */
/*   Updated: 2024/12/12 13:39:20 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*null_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

char	*ft_strnjoin(char **s1, char *s2, int n)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc((ft_strlen(*s1) + n + 1) * sizeof (char));
	if (!tab)
		return (null_free(s1));
	while (*s1 && (*s1)[i])
	{
		tab[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	null_free(s1);
	return (tab);
}

char	*ft_substr(char **s, int start)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc((ft_strlen(*s) - start + 2) * sizeof (char));
	if (!tab)
		return (null_free(s));
	while (i < ft_strlen(*s) - start)
	{
		tab[i] = (*s)[i + start];
		i++;
	}
	tab[i] = '\0';
	null_free(s);
	return (tab);
}
