/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:31:37 by nseon             #+#    #+#             */
/*   Updated: 2025/03/04 12:02:03 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <X11/keysym.h>
#include "mlx.h"
#include "draw.h"
#include "fdf.h"

int	click(int keycode, int x, int y, t_data *data)
{
	if (keycode == 1)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		if (keycode == 1)
			data->click = 1;
	}
	if (keycode == 4)
	{
		mlx_destroy_image(data->link, data->img);
		data->z += 0.1;
		print_map(data);
	}
	if (keycode == 5)
	{
		mlx_destroy_image(data->link, data->img);
		data->z -= 0.1;
		print_map(data);
	}
	return (0);
}

int	unclick(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		data->click = 0;
	return (0);
}

int	redirect_signals(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == 0)
		close_window(data);
	if (keycode == 65453)
	{
		mlx_destroy_image(data->link, data->img);
		if (data->lod < data->size_line / 2)
			data->lod += 1;
		print_map(data);
	}
	if (keycode == 65451)
	{
		mlx_destroy_image(data->link, data->img);
		if (data->lod >= 2)
			data->lod -= 1;
		print_map(data);
	}
	return (0);
}
