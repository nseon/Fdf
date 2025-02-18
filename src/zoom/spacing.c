/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:58 by nseon             #+#    #+#             */
/*   Updated: 2025/02/18 16:15:18 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_printf.h"

void	spacing(t_data *data)
{
	int	x;
	int	y;
	int	zoom;
	int	shift_x;
	int	shift_y;

	y = 0;
	if (data->size_line > data->nb_line)
		zoom = WIDTH / (data->size_line << 1);
	else
		zoom = HEIGHT / (data->size_line << 1);
	shift_x = (WIDTH - (data->size_line - 1) * (zoom + 1)) >> 1;
	shift_y = (HEIGHT - (data->nb_line - 1) * (zoom + 1)) >> 1;
	while (y < data->nb_line)
	{
		x = 0;
		while (x < data->size_line)
		{
			data->pts[y * data->size_line + x].x += zoom * x + shift_x + WIDTH / 8;
			data->pts[y * data->size_line + x].y += zoom * y + shift_y;
			data->pts[y * data->size_line + x].z *= 3;
			x++;
		}
		y++;
	}
}
