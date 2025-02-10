/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:55:23 by nseon             #+#    #+#             */
/*   Updated: 2025/02/10 19:11:03 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "struct.h"

char	*ft_realloc(char *tab, int plus)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(tab) + plus + 1);
	if (!str)
		return (NULL);
	while (tab[i])
	{}
}

char	**map(int fd)
{
	t_point	*pts;
	char	**tab;
	int		x;
	int		y;

	y = 0;
	x = 0;
	tab = ft_split(get_next_line(fd), ' ');
	if (!tab)
		return (NULL);
	while (tab[x])
	{
		pts[x].x = x;
		pts[x].y = y;
		pts[x].z = ft_atoi(tab[x]);
		x++;
	}
	return (tab);
}
