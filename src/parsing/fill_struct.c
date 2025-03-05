/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:47 by nseon             #+#    #+#             */
/*   Updated: 2025/03/05 16:38:26 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "stdlib.h"
#include "fdf.h"
#include "libft.h"

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

int	fill_link(t_data *data)
{
	data->link = mlx_init();
	if (!data->link)
		return (free(data->pts), 1);
	data->window = mlx_new_window(data->link, WIDTH, HEIGHT, "FDF");
	if (!data->window)
	{
		mlx_destroy_display(data->link);
		free(data->link);
		return (free(data->pts), 1);
	}
	data->z = 1;
	data->click = 0;
	data->lod = 1;
	return (0);
}
