/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:47 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 18:05:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "stdlib.h"
#include <X11/keysym.h>
#include "parsing.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == 0)
		mlx_loop_end(data->link);
	return (0);
}

int	fill_link(t_data *data)
{
	data->link = mlx_init();
	if (!data->link)
		return (1);
	data->window = mlx_new_window(data->link, WIDTH, HEIGHT, "FDF");
	if (!data->window)
	{
		mlx_destroy_display(data->link);
		return (close_window(0, data));
	}
	return (0);
}
