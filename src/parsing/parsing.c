/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:55:23 by nseon             #+#    #+#             */
/*   Updated: 2025/02/20 18:45:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "struct.h"
#include "ft_printf.h"
#include "fdf.h"
#include "parsing.h"

int	count_w(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	pts_realloc(t_data *data, int nb_lines)
{
	t_point	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(t_point) * data->size_line * (nb_lines + 1));
	if (!temp)
		close_window(data);
	while (i < data->size_line * (nb_lines))
	{
		temp[i] = data->pts[i];
		i++;
	}
	free(data->pts);
	data->pts = temp;
	return (0);
}

int	map(int fd, t_data *data)
{
	char	*tab;
	char	**z;
	int		y;

	y = 0;
	tab = (char *)1;
	while (tab)
	{
		data->nb_line = y;
		tab = get_next_line(fd);
		if (!tab)
			return (1);
		tab[ft_strlen(tab) - 1] = ' ';
		z = ft_split(tab, ' ');
		if (y == 0)
			data->size_line = count_w(z);
		pts_realloc(data, y);
		fill_data(data, y, z);
		free_split(z);
		free(tab);
		y++;
	}
	return (0);
}
