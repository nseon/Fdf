/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:41 by nseon             #+#    #+#             */
/*   Updated: 2025/02/12 15:29:15 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->nb_line)
	{
		x = 0;
		while (x < data->size_line)
		{
			if (x)
				draw_line(data, data->pts[y * data->size_line + x],
					data->pts[y * data->size_line + x - 1]);
			if (y)
				draw_line(data, data->pts[y * data->size_line + x],
					data->pts[(y - 1) * data->size_line + x]);
			x++;
		}
		y++;
	}
}
