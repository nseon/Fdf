/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/12 15:25:30 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*line(int i, char **left)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc((i + 1) * sizeof (char));
	if (!str)
		return (null_free(left));
	while (j < i)
	{
		str[j] = (*left)[j];
		j++;
	}
	str[j] = '\0';
	*left = ft_substr(left, i);
	if (!(*left))
		return (null_free(&str));
	if ((*left)[0] == '\0')
		null_free(left);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		buff[BUFFER_SIZE];
	int			i;
	int			nb;

	nb = BUFFER_SIZE;
	while (!(nb < BUFFER_SIZE && left))
	{
		i = 0;
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1 || (nb == 0 && (!left || (left && left[0] == '\0'))))
			return (null_free(&left));
		left = ft_strnjoin(&left, buff, nb);
		if (!left)
			return (0);
		while (left[i])
		{
			if (left[i] == '\n')
				return (line(i + 1, &left));
			i++;
		}
	}
	return (line(i, &left));
}
