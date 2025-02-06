/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:03:30 by nseon             #+#    #+#             */
/*   Updated: 2024/11/14 15:34:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	tab = ft_calloc(ft_strlen(s) + 1, sizeof (char));
	if (tab == NULL)
		return (0);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
