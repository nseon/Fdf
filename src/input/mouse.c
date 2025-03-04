/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:33:08 by nseon             #+#    #+#             */
/*   Updated: 2025/03/04 12:02:23 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"
#include "mlx.h"

int	move_mouse(int x, int y, t_data *data)
{
	if (data->click)
	{
		mlx_destroy_image(data->link, data->img);
		if (x > data->mouse_x)
			data->shift_x += x - data->mouse_x;
		if (x < data->mouse_x)
			data->shift_x -= data->mouse_x - x;
		if (y > data->mouse_y)
			data->shift_y += y - data->mouse_y;
		if (y < data->mouse_y)
			data->shift_y -= data->mouse_y - y;
		data->mouse_x = x;
		data->mouse_y = y;
		print_map(data);
	}
	return (0);
}
