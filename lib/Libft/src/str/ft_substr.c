/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:07:03 by nseon             #+#    #+#             */
/*   Updated: 2024/11/13 14:10:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	n;
	size_t	size;

	if (start >= ft_strlen(s))
		size = 0;
	else if (ft_strlen(s) - start >= len)
		size = len;
	else
		size = ft_strlen(s) - start;
	n = 0;
	tab = ft_calloc(size + 1, sizeof (char));
	if (tab == NULL)
		return (0);
	while (n < size && n < len && s[n + start])
	{
		tab[n] = s[n + start];
		n++;
	}
	return (tab);
}
