/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:55:23 by nseon             #+#    #+#             */
/*   Updated: 2025/02/11 16:34:59 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "struct.h"
#include "ft_printf.h"

int	pts_realloc(t_data *data, int nb_lines)
{
	t_point	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(t_point) * data->size_line * nb_lines + 1);
	if (!temp)
		return (1);
	while (i < data->size_line * (nb_lines))
	{
		ft_printf("%d\n", i);
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
	int		x;

	x = 0;
	y = 0;
	tab = (char *)1;
	while (tab)
	{
		tab = get_next_line(fd);
		data->size_line = count_w(tab, ' ');
		z = ft_split(tab, ' ');
		ft_printf("%d\n", y);
		pts_realloc(data, y);
		ft_printf("0000000000000000\n");
		while (x < data->size_line)
		{
			data->pts[y * data->size_line + x].x = x;
			data->pts[y * data->size_line + x].y = y;
			data->pts[y * data->size_line + x].z = ft_atoi(z[x]);
			x++;
		}
		y++;
	}
	return (0);
}
