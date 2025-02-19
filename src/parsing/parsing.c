/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:55:23 by nseon             #+#    #+#             */
/*   Updated: 2025/02/19 18:07:04 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "struct.h"
#include "ft_printf.h"
#include "fdf.h"

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

void	fill_data(t_data *data, int y, char **z)
{
	int	x;
	int	comp_z;

	x = -1;
	while (++x < data->size_line)
	{
		data->pts[y * data->size_line + x].x = x;
		data->pts[y * data->size_line + x].y = y;
		data->pts[y * data->size_line + x].z = ft_atoi(z[x]);
		comp_z = data->pts[y * data->size_line + x].z;
		if (comp_z < 0)
			comp_z *= -1;
		if (comp_z > data->max_z)
			data->max_z = comp_z;
		data->pts[y * data->size_line + x].color = 0xFFFFFF;
	}
}

int	map(int fd, t_data *data)
{
	char	*tab;
	char	**z;
	int		y;

	y = 0;
	tab = (char *)1;
	data->max_z = 0;
	while (tab)
	{
		data->nb_line = y;
		if (tab != (char *)1)
			free(tab);
		tab = get_next_line(fd);
		if (!tab)
			return (1);
		z = ft_split(tab, ' ');
		data->size_line = count_w(z);
		pts_realloc(data, y);
		fill_data(data, y, z);
		free_split(z);
		y++;
	}
	return (0);
}
